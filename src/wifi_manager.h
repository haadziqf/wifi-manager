#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <ArduinoJson.h>
#include "connection_log.h"

// WiFi Configuration
#define AP_SSID "AccessPointWiFi"
#define AP_PASSWORD "12345678"
#define AP_CHANNEL 1
#define AP_MAX_CONN 4

// Web Server Configuration
#define WEB_SERVER_PORT 80
#define DEVICE_NAME "AccessPointWiFi"

// System Configuration
#define CONFIG_VERSION "1.0.0"
#define EEPROM_SIZE 512
#define CONFIG_START_ADDR 0
#define MAX_NETWORKS 5
#define MAX_CONNECT_ATTEMPTS 2

// Timeouts
#define WIFI_CONNECT_TIMEOUT 10000  // 20 seconds
#define AP_MODE_TIMEOUT 300000      // 5 minutes
#define WIFI_CHECK_INTERVAL 15000   // 30 seconds

// Debug Configuration
#define DEBUG_MODE true
#define SERIAL_BAUD 115200

struct WiFiCredentials {
    char ssid[32];
    char password[64];
    bool isActive;
};

struct WiFiNetwork {
    String ssid;
    int rssi;
    bool isEncrypted;
};

class WiFiManager {
private:
    ESP8266WebServer server;
    ConnectionLog connectionLog;
    bool apMode;
    WiFiCredentials networks[MAX_NETWORKS];
    int currentNetworkIndex;
    unsigned long lastWiFiCheck;
    int connectAttempts;
    
    void setupAP();
    void setupWebServer();
    void handleRoot();
    void handleConnect();
    void handleStatus();
    void handleSaveNetwork();
    void handleListNetworks();
    void handleDeleteNetwork();
    void handleScanNetworks();
    void handleApSettings();
    void handleGetApSettings();
    void handleConnectionHistory();
    void handleNetworkStats();
    
    bool loadCredentials();
    bool saveCredentials();
    bool connectToSavedNetwork();
    void clearCredentials();
    void checkWiFiConnection();
    void fallbackToAPMode();
    
public:
    WiFiManager();
    void begin();
    void handleClient();
    bool isAPMode();
    String getStatus();
    bool connectToWiFi(const char* ssid, const char* password);
    void startAPMode();
    void stopAPMode();
    bool addNetwork(const char* ssid, const char* password);
    bool removeNetwork(const char* ssid);
    String getNetworksList();
};

#endif // WIFI_MANAGER_H 