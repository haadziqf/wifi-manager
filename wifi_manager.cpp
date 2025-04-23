#include "wifi_manager.h"
#include "web_interface.h"
#include <EEPROM.h>
#include <Esp.h> // Added for ESP functions

// ... existing code ...

String WiFiManager::getStatus() {
    StaticJsonDocument<300> doc; // Increased size
    doc["mode"] = apMode ? "AP" : "STA";
    doc["connected"] = WiFi.status() == WL_CONNECTED;
    doc["ip"] = apMode ? WiFi.softAPIP().toString() : WiFi.localIP().toString();
    doc["ssid"] = WiFi.SSID();
    doc["rssi"] = WiFi.RSSI();
    // Add performance monitoring info
    doc["uptime_s"] = millis() / 1000; // Uptime in seconds
    doc["free_heap"] = ESP.getFreeHeap(); // Free heap memory

    String output;
    serializeJson(doc, output);
    return output;
}

// ... existing code ...

void WiFiManager::clearCredentials() {
    memset(networks, 0, sizeof(networks));
    if (!saveCredentials()) {
        if (DEBUG_MODE) {
            Serial.println("WiFiManager: Error clearing credentials (EEPROM save failed)");
        }
    }
}

bool WiFiManager::addNetwork(const char* ssid, const char* password) {
    // Check if network already exists (update password if it does)
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (networks[i].isActive && strcmp(networks[i].ssid, ssid) == 0) {
            // Update password for existing network
            if (strcmp(networks[i].password, password) != 0) { // Only save if password changed
                 strcpy(networks[i].password, password);
                 if (!saveCredentials()) {
                    if (DEBUG_MODE) {
                        Serial.print("WiFiManager: Error updating network password (EEPROM save failed): ");
                        Serial.println(ssid);
                    }
                    // Optional: Revert password change in memory?
                    return false; // Indicate failure
                 }
            }
            return true; // Indicate success (found existing or updated)
        }
    }

    // Find empty slot to add new network
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (!networks[i].isActive) {
            strcpy(networks[i].ssid, ssid);
            strcpy(networks[i].password, password);
            networks[i].isActive = true;
            if (!saveCredentials()) {
                 if (DEBUG_MODE) {
                    Serial.print("WiFiManager: Error adding new network (EEPROM save failed): ");
                    Serial.println(ssid);
                }
                networks[i].isActive = false; // Revert change in memory on failure
                // Clear the failed entry
                memset(&networks[i], 0, sizeof(WiFiCredentials));
                return false; // Indicate failure
            }
             if (DEBUG_MODE) {
                Serial.print("WiFiManager: Network added: ");
                Serial.println(ssid);
            }
            return true; // Indicate success
        }
    }

    if (DEBUG_MODE) {
        Serial.println("WiFiManager: No empty slots to add network.");
    }
    return false; // No empty slots
}

bool WiFiManager::removeNetwork(const char* ssid) {
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (networks[i].isActive && strcmp(networks[i].ssid, ssid) == 0) {
            networks[i].isActive = false; // Mark as inactive
            // Clear the data for the removed network
            memset(&networks[i], 0, sizeof(WiFiCredentials));

            if (!saveCredentials()) {
                if (DEBUG_MODE) {
                    Serial.print("WiFiManager: Error removing network (EEPROM save failed): ");
                    Serial.println(ssid);
                }
                // Attempt to revert the change in memory
                // Note: We lost the original password here, could reload from EEPROM if critical
                networks[i].isActive = true;
                strcpy(networks[i].ssid, ssid);
                // networks[i].password would be wrong here

                return false; // Indicate failure
            }
             if (DEBUG_MODE) {
                Serial.print("WiFiManager: Network removed: ");
                Serial.println(ssid);
            }
            return true; // Indicate success
        }
    }
    if (DEBUG_MODE) {
        Serial.print("WiFiManager: Network not found for removal: ");
        Serial.println(ssid);
    }
    return false; // Network not found
}

// ... existing code ...

void WiFiManager::handleRoot() {
    // Send chunked response
    server.setContentLength(CONTENT_LENGTH_UNKNOWN);
    // Specify UTF-8 charset in Content-Type header
    server.sendHeader("Content-Type", "text/html; charset=UTF-8", true);
    server.send(200); // Send status code (mandatory)

    // Send HTML parts
    server.sendContent_P(HTML_HEAD_START);
    server.sendContent(DEVICE_NAME); // Send title string
    server.sendContent_P(HTML_HEAD_END);
    server.sendContent_P(CSS_STYLES);
    server.sendContent_P(HTML_BODY_START);
    server.sendContent(DEVICE_NAME); // Send title string for H1
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

// ... existing code ...
