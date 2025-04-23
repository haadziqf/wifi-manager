#ifndef CONNECTION_LOG_H
#define CONNECTION_LOG_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <vector>
#include <map>

struct ConnectionEntry {
    String ssid;
    int rssi;
    bool success;
    unsigned long timestamp;
};

class ConnectionLog {
private:
    static const size_t MAX_HISTORY_SIZE = 10;
    std::vector<ConnectionEntry> history;
    std::map<String, int> successCount;
    std::map<String, int> failureCount;
    
    void trimHistory();
    String getFormattedTimestamp(unsigned long timestamp);

public:
    ConnectionLog();
    
    void logConnect(const String& ssid, int rssi);
    void logFailure(const String& ssid);
    String getConnectionHistory();
    String getNetworkStatistics();
};

#endif // CONNECTION_LOG_H 