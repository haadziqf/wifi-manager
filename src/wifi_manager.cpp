#include "wifi_manager.h"
#include "web_interface.h"
#include <EEPROM.h>

WiFiManager::WiFiManager() : server(WEB_SERVER_PORT), apMode(false), currentNetworkIndex(0), lastWiFiCheck(0), connectAttempts(0) {
    EEPROM.begin(EEPROM_SIZE);
    loadCredentials();
}

void WiFiManager::begin() {
    if (DEBUG_MODE) {
        Serial.begin(SERIAL_BAUD);
        Serial.println("WiFiManager: Initializing...");
    }
    
    setupWebServer();
    server.begin();
    
    if (DEBUG_MODE) {
        Serial.println("WiFiManager: Web server started");
    }
    
    // Try to connect to saved network first (limited to 2 attempts)
    int attempts = 0;
    while (attempts < MAX_CONNECT_ATTEMPTS) {
        if (connectToSavedNetwork()) {
            return; // Successfully connected
        }
        attempts++;
        if (DEBUG_MODE) {
            Serial.print("Connection attempt ");
            Serial.print(attempts);
            Serial.print(" of ");
            Serial.println(MAX_CONNECT_ATTEMPTS);
        }
        delay(1000); // Wait before next attempt
    }
    
    // If all attempts fail, fall back to AP mode
    fallbackToAPMode();
}

void WiFiManager::setupAP() {
    // Check if custom AP settings exist in EEPROM
    int apSettingsAddr = EEPROM_SIZE - 100;
    bool useCustomSettings = false;
    char customSSID[33] = {0};  // 32 chars + null terminator
    char customPassword[65] = {0};  // 64 chars + null terminator

    // Check for the AP marker
    if (EEPROM.read(apSettingsAddr) == 'A' && EEPROM.read(apSettingsAddr + 1) == 'P') {
        // Read the custom SSID
        for (int i = 0; i < 32; i++) {
            char c = EEPROM.read(apSettingsAddr + 2 + i);
            if (c == 0) break;  // Stop at null terminator
            customSSID[i] = c;
        }
        
        // Read the custom password
        for (int i = 0; i < 64; i++) {
            char c = EEPROM.read(apSettingsAddr + 34 + i);
            if (c == 0) break;  // Stop at null terminator
            customPassword[i] = c;
        }
        
        useCustomSettings = (strlen(customSSID) > 0);
    }

    // Start the AP with either custom or default settings
    if (useCustomSettings) {
        WiFi.softAP(customSSID, strlen(customPassword) > 0 ? customPassword : AP_PASSWORD, AP_CHANNEL, 0, AP_MAX_CONN);
        
        if (DEBUG_MODE) {
            Serial.print("WiFiManager: AP Mode started with custom SSID: ");
            Serial.println(customSSID);
            Serial.print("IP Address: ");
            Serial.println(WiFi.softAPIP());
        }
    } else {
        WiFi.softAP(AP_SSID, AP_PASSWORD, AP_CHANNEL, 0, AP_MAX_CONN);
        
        if (DEBUG_MODE) {
            Serial.print("WiFiManager: AP Mode started with default SSID: ");
            Serial.println(AP_SSID);
            Serial.print("IP Address: ");
            Serial.println(WiFi.softAPIP());
        }
    }
}

void WiFiManager::setupWebServer() {
    server.on("/", HTTP_GET, [this]() { handleRoot(); });
    server.on("/connect", HTTP_POST, [this]() { handleConnect(); });
    server.on("/status", HTTP_GET, [this]() { handleStatus(); });
    server.on("/networks", HTTP_GET, [this]() { handleListNetworks(); });
    server.on("/save", HTTP_POST, [this]() { handleSaveNetwork(); });
    server.on("/delete", HTTP_POST, [this]() { handleDeleteNetwork(); });
    server.on("/scan", HTTP_GET, [this]() { handleScanNetworks(); });
    server.on("/ap-settings", HTTP_POST, [this]() { handleApSettings(); });
    server.on("/get-ap-settings", HTTP_GET, [this]() { handleGetApSettings(); });
    server.on("/history", HTTP_GET, [this]() { handleConnectionHistory(); });
    server.on("/stats", HTTP_GET, [this]() { handleNetworkStats(); });
}

void WiFiManager::handleRoot() {
    // Send chunked response
    server.setContentLength(CONTENT_LENGTH_UNKNOWN);
    server.sendHeader("Content-Type", "text/html", true);
    server.send(200); // Send status code (mandatory)

    // Get the current AP SSID to use as device name
    String deviceName;
    int apSettingsAddr = EEPROM_SIZE - 100;
    
    // Check if custom AP settings exist in EEPROM
    if (EEPROM.read(apSettingsAddr) == 'A' && EEPROM.read(apSettingsAddr + 1) == 'P') {
        // Read the custom SSID
        char customSSID[33] = {0};
        for (int i = 0; i < 32; i++) {
            char c = EEPROM.read(apSettingsAddr + 2 + i);
            if (c == 0) break;
            customSSID[i] = c;
        }
        deviceName = String(customSSID);
    } else {
        // Use default device name
        deviceName = DEVICE_NAME;
    }

    server.sendContent_P(HTML_HEAD_START);
    server.sendContent(deviceName); // Send title string with current AP name
    server.sendContent_P(HTML_HEAD_END);
    server.sendContent_P(CSS_STYLES);
    server.sendContent_P(HTML_BODY_START);
    server.sendContent(deviceName); // Send title string for H1 with current AP name
    server.sendContent_P(HTML_BODY_CONTINUE);
    server.sendContent_P(HTML_CONNECT_CARD_START);
    server.sendContent_P(CONTENT_TEMPLATE);
    server.sendContent_P(HTML_CONNECT_CARD_END);
    server.sendContent_P(HTML_MONITOR_CARD);
    server.sendContent_P(HTML_HISTORY_CARD);
    server.sendContent_P(HTML_STATS_CARD);
    server.sendContent_P(HTML_SETTINGS_CARD);
    server.sendContent_P(HTML_FOOTER);
    server.sendContent_P(HTML_MODAL);
    server.sendContent_P(HTML_SCRIPT_START);
    server.sendContent_P(JS_SCRIPT);
    server.sendContent_P(HTML_SCRIPT_END);
    server.sendContent(""); // End chunked response
}

void WiFiManager::handleConnect() {
    if (server.hasArg("plain")) {
        String json = server.arg("plain");
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, json);
        
        if (!error) {
            const char* ssid = doc["ssid"];
            const char* password = doc["password"];
            
            if (connectToWiFi(ssid, password)) {
                server.send(200, "application/json", "{\"message\":\"Connected successfully\"}");
            } else {
                fallbackToAPMode();
                server.send(400, "application/json", "{\"message\":\"Connection failed, falling back to AP mode\"}");
            }
        } else {
            server.send(400, "application/json", "{\"message\":\"Invalid JSON\"}");
        }
    } else {
        server.send(400, "application/json", "{\"message\":\"Missing data\"}");
    }
}

void WiFiManager::handleSaveNetwork() {
    if (server.hasArg("plain")) {
        String json = server.arg("plain");
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, json);
        
        if (!error) {
            const char* ssid = doc["ssid"];
            const char* password = doc["password"];
            
            if (addNetwork(ssid, password)) {
                server.send(200, "application/json", "{\"message\":\"Network saved\"}");
            } else {
                server.send(400, "application/json", "{\"message\":\"Failed to save network\"}");
            }
        } else {
            server.send(400, "application/json", "{\"message\":\"Invalid JSON\"}");
        }
    } else {
        server.send(400, "application/json", "{\"message\":\"Missing data\"}");
    }
}

void WiFiManager::handleListNetworks() {
    server.send(200, "application/json", getNetworksList());
}

void WiFiManager::handleDeleteNetwork() {
    if (server.hasArg("plain")) {
        String json = server.arg("plain");
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, json);
        
        if (!error) {
            const char* ssid = doc["ssid"];
            
            if (removeNetwork(ssid)) {
                server.send(200, "application/json", "{\"message\":\"Network deleted\"}");
            } else {
                server.send(400, "application/json", "{\"message\":\"Failed to delete network\"}");
            }
        } else {
            server.send(400, "application/json", "{\"message\":\"Invalid JSON\"}");
        }
    } else {
        server.send(400, "application/json", "{\"message\":\"Missing data\"}");
    }
}

void WiFiManager::handleScanNetworks() {
    if (DEBUG_MODE) {
        Serial.println("WiFiManager: Scanning for networks...");
    }
    
    int n = WiFi.scanNetworks();
    if (DEBUG_MODE) {
        Serial.print("WiFiManager: Found ");
        Serial.print(n);
        Serial.println(" networks");
    }
    
    StaticJsonDocument<1024> doc;
    JsonArray networksArray = doc.createNestedArray("networks");
    
    for (int i = 0; i < n; i++) {
        JsonObject network = networksArray.createNestedObject();
        network["ssid"] = WiFi.SSID(i);
        network["rssi"] = WiFi.RSSI(i);
        network["isEncrypted"] = WiFi.encryptionType(i) != ENC_TYPE_NONE;
        
        if (DEBUG_MODE) {
            Serial.print("Network: ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" RSSI: ");
            Serial.println(WiFi.RSSI(i));
        }
    }
    
    String output;
    serializeJson(doc, output);
    server.send(200, "application/json", output);
}

void WiFiManager::handleStatus() {
    server.send(200, "application/json", getStatus());
}

void WiFiManager::handleClient() {
    server.handleClient();
    
    // Check WiFi connection periodically
    if (millis() - lastWiFiCheck > WIFI_CHECK_INTERVAL) {
        checkWiFiConnection();
        lastWiFiCheck = millis();
    }
}

void WiFiManager::checkWiFiConnection() {
    if (!apMode && WiFi.status() != WL_CONNECTED) {
        if (DEBUG_MODE) {
            Serial.println("WiFiManager: Connection lost, trying to reconnect...");
        }
        
        connectAttempts++;
        if (connectAttempts >= MAX_CONNECT_ATTEMPTS) {
            if (DEBUG_MODE) {
                Serial.println("WiFiManager: Max connection attempts reached, falling back to AP mode");
            }
            fallbackToAPMode();
            return;
        }
        
        // Try to reconnect to the current network
        if (currentNetworkIndex >= 0 && currentNetworkIndex < MAX_NETWORKS && 
            networks[currentNetworkIndex].isActive) {
            if (!connectToWiFi(networks[currentNetworkIndex].ssid, 
                             networks[currentNetworkIndex].password)) {
                // If reconnection fails, try other saved networks
                if (!connectToSavedNetwork()) {
                    fallbackToAPMode();
                }
            }
        } else {
            // If no current network, try all saved networks
            if (!connectToSavedNetwork()) {
                fallbackToAPMode();
            }
        }
    }
}

void WiFiManager::fallbackToAPMode() {
    if (DEBUG_MODE) {
        Serial.println("WiFiManager: Falling back to AP mode");
    }
    
    // Disconnect from current WiFi
    WiFi.disconnect();
    
    // Start AP mode
    startAPMode();
}

bool WiFiManager::isAPMode() {
    return apMode;
}

String WiFiManager::getStatus() {
    StaticJsonDocument<200> doc;
    doc["mode"] = apMode ? "AP" : "STA";
    doc["connected"] = WiFi.status() == WL_CONNECTED;
    doc["ip"] = apMode ? WiFi.softAPIP().toString() : WiFi.localIP().toString();
    
    // Include device name (based on current AP SSID)
    String deviceName;
    int apSettingsAddr = EEPROM_SIZE - 100;
    
    // Check if custom AP settings exist in EEPROM
    if (EEPROM.read(apSettingsAddr) == 'A' && EEPROM.read(apSettingsAddr + 1) == 'P') {
        // Read the custom SSID
        char customSSID[33] = {0};
        for (int i = 0; i < 32; i++) {
            char c = EEPROM.read(apSettingsAddr + 2 + i);
            if (c == 0) break;
            customSSID[i] = c;
        }
        deviceName = String(customSSID);
    } else {
        // Use default device name
        deviceName = DEVICE_NAME;
    }
    
    doc["deviceName"] = deviceName;
    doc["ssid"] = WiFi.SSID();
    doc["rssi"] = WiFi.RSSI();
    
    // Calculate uptime in seconds if connected
    if (WiFi.status() == WL_CONNECTED) {
        static unsigned long connectionTime = millis();
        if (!doc["connected"]) {
            connectionTime = millis(); // Reset connection time if just connected
        }
        doc["uptime_s"] = (millis() - connectionTime) / 1000;
    }
    
    String output;
    serializeJson(doc, output);
    return output;
}

bool WiFiManager::connectToWiFi(const char* ssid, const char* password) {
    if (DEBUG_MODE) {
        Serial.print("WiFiManager: Connecting to ");
        Serial.println(ssid);
    }
    
    WiFi.begin(ssid, password);
    
    unsigned long startAttemptTime = millis();
    int attemptCount = 0;
    int countdown = WIFI_CONNECT_TIMEOUT / 1000; // Convert to seconds
    
    while (WiFi.status() != WL_CONNECTED && 
           millis() - startAttemptTime < WIFI_CONNECT_TIMEOUT &&
           attemptCount < MAX_CONNECT_ATTEMPTS) {
        delay(100);
        
        // Update countdown every second
        if (DEBUG_MODE && (millis() - startAttemptTime) % 1000 == 0) {
            Serial.print("Connection attempt ");
            Serial.print(attemptCount + 1);
            Serial.print(" of ");
            Serial.print(MAX_CONNECT_ATTEMPTS);
            Serial.print(" - Time remaining: ");
            Serial.print(countdown);
            Serial.println(" seconds");
            countdown--;
        }
        
        // Check if we need to increment attempt counter
        if ((millis() - startAttemptTime) % (WIFI_CONNECT_TIMEOUT / MAX_CONNECT_ATTEMPTS) == 0) {
            attemptCount++;
            if (attemptCount < MAX_CONNECT_ATTEMPTS) {
                Serial.println("Retrying connection...");
                WiFi.disconnect();
                delay(1000);
                WiFi.begin(ssid, password);
                countdown = WIFI_CONNECT_TIMEOUT / 1000; // Reset countdown
            }
        }
    }
    
    if (WiFi.status() == WL_CONNECTED) {
        if (DEBUG_MODE) {
            Serial.print("WiFiManager: Connected! IP address: ");
            Serial.println(WiFi.localIP());
        }
        apMode = false;
        connectAttempts = 0;
        connectionLog.logConnect(ssid, WiFi.RSSI()); // Log successful connection
        return true;
    }
    
    if (DEBUG_MODE) {
        Serial.println("WiFiManager: Connection failed after 2 attempts!");
    }
    connectionLog.logFailure(ssid); // Log failed connection
    return false;
}

bool WiFiManager::loadCredentials() {
    EEPROM.get(CONFIG_START_ADDR, networks);
    return true;
}

bool WiFiManager::saveCredentials() {
    EEPROM.put(CONFIG_START_ADDR, networks);
    return EEPROM.commit();
}

bool WiFiManager::connectToSavedNetwork() {
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (networks[i].isActive) {
            if (connectToWiFi(networks[i].ssid, networks[i].password)) {
                currentNetworkIndex = i;
                return true;
            }
        }
    }
    return false;
}

void WiFiManager::clearCredentials() {
    memset(networks, 0, sizeof(networks));
    saveCredentials();
}

bool WiFiManager::addNetwork(const char* ssid, const char* password) {
    // Check if network already exists
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (networks[i].isActive && strcmp(networks[i].ssid, ssid) == 0) {
            strcpy(networks[i].password, password);
            return saveCredentials();
        }
    }
    
    // Find empty slot
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (!networks[i].isActive) {
            strcpy(networks[i].ssid, ssid);
            strcpy(networks[i].password, password);
            networks[i].isActive = true;
            return saveCredentials();
        }
    }
    
    return false; // No empty slots
}

bool WiFiManager::removeNetwork(const char* ssid) {
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (networks[i].isActive && strcmp(networks[i].ssid, ssid) == 0) {
            networks[i].isActive = false;
            return saveCredentials();
        }
    }
    return false;
}

String WiFiManager::getNetworksList() {
    StaticJsonDocument<512> doc;
    JsonArray networksArray = doc.createNestedArray("networks");
    
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (networks[i].isActive) {
            JsonObject network = networksArray.createNestedObject();
            network["ssid"] = networks[i].ssid;
        }
    }
    
    String output;
    serializeJson(doc, output);
    return output;
}

void WiFiManager::startAPMode() {
    if (!apMode) {
        setupAP();
        apMode = true;
    }
}

void WiFiManager::stopAPMode() {
    if (apMode) {
        WiFi.softAPdisconnect(true);
        apMode = false;
        if (DEBUG_MODE) {
            Serial.println("WiFiManager: AP Mode stopped");
        }
    }
}

void WiFiManager::handleApSettings() {
    if (server.hasArg("plain")) {
        String json = server.arg("plain");
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, json);
        
        if (!error) {
            const char* ssid = doc["ssid"];
            const char* password = doc["password"];
            
            if (strlen(ssid) > 0) {
                // Save the AP settings to EEPROM for persistence
                int apSettingsAddr = EEPROM_SIZE - 100; // Use last 100 bytes for AP settings
                
                // Check if we need to keep the existing password
                char existingPassword[65] = {0};
                bool keepExistingPassword = (password == NULL || strlen(password) == 0);
                
                if (keepExistingPassword && 
                    EEPROM.read(apSettingsAddr) == 'A' && 
                    EEPROM.read(apSettingsAddr + 1) == 'P') {
                    // Read existing password from EEPROM
                    for (int i = 0; i < 64; i++) {
                        existingPassword[i] = EEPROM.read(apSettingsAddr + 34 + i);
                        if (existingPassword[i] == 0) break;
                    }
                }
                
                // Write a marker to identify AP settings
                EEPROM.write(apSettingsAddr, 'A');
                EEPROM.write(apSettingsAddr + 1, 'P');
                
                // Write SSID (up to 32 chars)
                for (int i = 0; i < 32; i++) {
                    if (i < strlen(ssid)) {
                        EEPROM.write(apSettingsAddr + 2 + i, ssid[i]);
                    } else {
                        EEPROM.write(apSettingsAddr + 2 + i, 0);
                    }
                }
                
                // Write password (up to 64 chars)
                for (int i = 0; i < 64; i++) {
                    if (keepExistingPassword) {
                        EEPROM.write(apSettingsAddr + 34 + i, existingPassword[i]);
                        if (existingPassword[i] == 0) break;
                    } else if (i < strlen(password)) {
                        EEPROM.write(apSettingsAddr + 34 + i, password[i]);
                    } else {
                        EEPROM.write(apSettingsAddr + 34 + i, 0);
                    }
                }
                
                // Commit changes to EEPROM
                if (EEPROM.commit()) {
                    if (DEBUG_MODE) {
                        Serial.print("WiFiManager: AP settings saved - SSID: ");
                        Serial.print(ssid);
                        if (!keepExistingPassword) {
                            Serial.print(", Password changed");
                        } else {
                            Serial.print(", Password preserved");
                        }
                        Serial.println();
                    }
                    
                    server.send(200, "application/json", 
                        "{\"message\":\"AP settings updated. Restart to apply changes.\"}");
                } else {
                    server.send(500, "application/json", 
                        "{\"message\":\"Failed to save AP settings to EEPROM\"}");
                }
            } else {
                server.send(400, "application/json", "{\"message\":\"Invalid SSID\"}");
            }
        } else {
            server.send(400, "application/json", "{\"message\":\"Invalid JSON\"}");
        }
    } else {
        server.send(400, "application/json", "{\"message\":\"Missing data\"}");
    }
}

void WiFiManager::handleGetApSettings() {
    StaticJsonDocument<200> doc;
    
    // Check if custom AP settings exist in EEPROM
    int apSettingsAddr = EEPROM_SIZE - 100;
    
    // Check for the AP marker
    if (EEPROM.read(apSettingsAddr) == 'A' && EEPROM.read(apSettingsAddr + 1) == 'P') {
        // Read the custom SSID
        char customSSID[33] = {0};
        for (int i = 0; i < 32; i++) {
            char c = EEPROM.read(apSettingsAddr + 2 + i);
            if (c == 0) break;
            customSSID[i] = c;
        }
        
        // For security, we don't send the actual password, just whether it exists
        bool hasPassword = false;
        for (int i = 0; i < 64; i++) {
            char c = EEPROM.read(apSettingsAddr + 34 + i);
            if (c != 0) {
                hasPassword = true;
                break;
            }
        }
        
        // Add to JSON response
        doc["ssid"] = customSSID;
        doc["password"] = hasPassword ? true : false;
    } else {
        // Return default settings
        doc["ssid"] = AP_SSID;
        doc["password"] = true; // Default has a password
    }
    
    String response;
    serializeJson(doc, response);
    server.send(200, "application/json", response);
}

void WiFiManager::handleConnectionHistory() {
    server.send(200, "application/json", connectionLog.getConnectionHistory());
}

void WiFiManager::handleNetworkStats() {
    server.send(200, "application/json", connectionLog.getNetworkStatistics());
} 