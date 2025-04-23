#include "wifi_manager.h"

WiFiManager wifiManager;

void setup() {
    wifiManager.begin();
    wifiManager.startAPMode();
}

void loop() {
    wifiManager.handleClient();
} 