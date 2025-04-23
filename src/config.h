#ifndef CONFIG_H
#define CONFIG_H

// WiFi Configuration
#define DEFAULT_AP_SSID "WiFiManager"
#define DEFAULT_AP_PASSWORD "12345678"

// Network Configuration
#define MAX_NETWORKS 20
#define MIN_RSSI -100
#define MAX_RSSI -30

// Connection Configuration
#define CONNECT_TIMEOUT 20000  // 20 seconds
#define RECONNECT_DELAY 5000   // 5 seconds

// Monitoring Configuration
#define MONITOR_INTERVAL 10000  // 10 seconds
#define STATUS_UPDATE_INTERVAL 1000  // 1 second

// EEPROM Configuration
#define EEPROM_SIZE 512
#define LAST_SSID_ADDR 0
#define LAST_PASS_ADDR 32

#endif // CONFIG_H 