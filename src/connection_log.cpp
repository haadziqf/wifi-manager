#include "connection_log.h"

ConnectionLog::ConnectionLog() {
    history.reserve(MAX_HISTORY_SIZE);
}

void ConnectionLog::logConnect(const String& ssid, int rssi) {
    ConnectionEntry entry = {
        ssid,
        rssi,
        true,
        millis()
    };
    
    history.push_back(entry);
    successCount[ssid]++;
    trimHistory();
}

void ConnectionLog::logFailure(const String& ssid) {
    ConnectionEntry entry = {
        ssid,
        0,
        false,
        millis()
    };
    
    history.push_back(entry);
    failureCount[ssid]++;
    trimHistory();
}

void ConnectionLog::trimHistory() {
    while (history.size() > MAX_HISTORY_SIZE) {
        history.erase(history.begin());
    }
}

String ConnectionLog::getFormattedTimestamp(unsigned long timestamp) {
    unsigned long seconds = timestamp / 1000;
    unsigned long minutes = seconds / 60;
    unsigned long hours = minutes / 60;
    
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%02lu:%02lu:%02lu", 
             hours % 24, minutes % 60, seconds % 60);
    return String(buffer);
}

String ConnectionLog::getConnectionHistory() {
    DynamicJsonDocument doc(1024);
    JsonArray events = doc.createNestedArray("events");
    
    for (const auto& entry : history) {
        JsonObject event = events.createNestedObject();
        event["timestamp"] = getFormattedTimestamp(entry.timestamp);
        event["ssid"] = entry.ssid;
        event["rssi"] = entry.rssi;
        event["success"] = entry.success;
    }
    
    String output;
    serializeJson(doc, output);
    return output;
}

String ConnectionLog::getNetworkStatistics() {
    DynamicJsonDocument doc(512);
    JsonObject stats = doc.createNestedObject("statistics");
    
    for (const auto& pair : successCount) {
        JsonObject network = stats.createNestedObject(pair.first);
        network["successful_connections"] = pair.second;
        network["failed_connections"] = failureCount[pair.first];
        network["success_rate"] = (float)pair.second / (pair.second + failureCount[pair.first]) * 100;
    }
    
    String output;
    serializeJson(doc, output);
    return output;
} 