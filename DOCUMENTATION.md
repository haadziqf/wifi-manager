# AccessPointWiFi Manager - Technical Documentation

This document provides detailed technical information about the AccessPointWiFi Manager, including architecture, code structure, and implementation details.

## System Architecture

The WiFi Manager is built on the ESP8266 platform and consists of several key components:

1. **WiFi Management System**: Handles scanning, connecting, and managing WiFi networks
2. **Web Server**: Provides the configuration interface and API endpoints
3. **Access Point Controller**: Manages the creation and configuration of the access point
4. **Storage Controller**: Handles saving and retrieving settings from EEPROM
5. **Web Interface**: The frontend UI written in HTML, CSS, and JavaScript

```
┌─────────────────────────────────────────┐
│               ESP8266                   │
│                                         │
│  ┌─────────────┐      ┌──────────────┐  │
│  │ WiFi Manager│◄────►│ Web Server   │  │
│  └─────────────┘      └──────────────┘  │
│         ▲                    ▲          │
│         │                    │          │
│         ▼                    ▼          │
│  ┌─────────────┐      ┌──────────────┐  │
│  │  AP Control │◄────►│ Web Interface│  │
│  └─────────────┘      └──────────────┘  │
│         ▲                               │
│         │                               │
│         ▼                               │
│  ┌─────────────┐                        │
│  │  Storage    │                        │
│  └─────────────┘                        │
└─────────────────────────────────────────┘
```

## Project Structure

```
/
├── src/
│   ├── wifi_manager.ino       # Main Arduino sketch
│   ├── wifi_manager.h         # Core functionality header
│   ├── web_interface.h        # Web UI HTML, CSS and JavaScript
│   └── storage.h              # EEPROM functions
├── README.md                  # Project overview
└── DOCUMENTATION.md           # Technical documentation
```

## Core Components

### WiFi Manager

The WiFi Manager component is responsible for:

- Scanning for available networks
- Connecting to configured networks
- Managing connection status
- Implementing fallback mechanisms
- Creating and configuring the access point

**Key Functions:**

```cpp
void setupWiFi()                    // Initialize WiFi components
void scanNetworks()                 // Scan for available networks
bool connectToWiFi(String ssid, String pass)  // Connect to a specific network
void createAccessPoint()            // Create AP when connection fails
void checkConnection()              // Periodic connection check
```

### Web Server

The web server handles all HTTP requests and provides API endpoints for:

- Serving the web interface
- Scanning networks
- Connecting to networks
- Managing device settings
- Providing status information

**Key API Endpoints:**

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/` | GET | Serves the main interface |
| `/scan` | GET | Triggers network scan and returns results |
| `/connect` | POST | Attempts connection to specified network |
| `/status` | GET | Returns current connection status |
| `/settings` | POST | Updates device settings |
| `/reset` | POST | Resets device settings |

**Response Format:**

```json
{
  "status": "success|error",
  "message": "Status message",
  "data": {
    "...": "Response data depends on endpoint"
  }
}
```

### Storage Controller

The storage system manages persistent data in the ESP8266's EEPROM:

- WiFi credentials (SSID, password)
- AP settings (name, password)
- Connection statistics
- Device configuration

**Data Structure:**

```cpp
struct WiFiCredentials {
  char ssid[32];
  char password[64];
  bool enabled;
  uint8_t priority;
};

struct APSettings {
  char ssid[32];
  char password[64];
  uint8_t channel;
  uint8_t maxConnections;
  bool hidden;
};

struct DeviceConfig {
  WiFiCredentials networks[MAX_NETWORKS];
  APSettings ap;
  uint8_t connectAttempts;
  bool apFallbackEnabled;
  unsigned long apTimeout;
};
```

## Web Interface

The web interface is built with modern HTML5, CSS3, and JavaScript, following iOS design guidelines:

1. **HTML Structure**: Semantic HTML5 with proper accessibility
2. **CSS**: Custom iOS-inspired design system with:
   - Custom variables for colors and dimensions
   - Responsive layout with media queries
   - Animations and transitions for interactions
3. **JavaScript**: Client-side code for:
   - AJAX requests to the API endpoints
   - Real-time status updates
   - User interface interactions
   - Form validation and submission

## Security Considerations

The WiFi Manager implements several security features:

1. **Password Protection**: AP is password protected
2. **Input Validation**: All user inputs are validated
3. **Password Hashing**: Passwords are securely stored
4. **Session Management**: Basic session handling
5. **HTTPS Support**: Optional with ESP8266 limitations

## Performance Optimization

The code is optimized for the ESP8266's limited resources:

1. **Memory Usage**: Careful management of dynamic memory
2. **Connection Stability**: Robust reconnection mechanisms
3. **Power Efficiency**: Sleep modes when appropriate
4. **Page Size**: Minimized HTML/CSS/JS for faster loading

## Troubleshooting

Common issues and solutions:

1. **Connection Fails**: Ensure correct credentials and network availability
2. **AP Not Visible**: Check if maximum connection limit is reached
3. **Web Interface Not Loading**: Clear browser cache or try another device
4. **Settings Not Saving**: Ensure EEPROM is functioning correctly
5. **Frequent Disconnections**: Check signal strength and power supply

## Custom Configuration

Advanced users can modify the following files:

1. **wifi_manager.h**: Core functionality and default settings
2. **web_interface.h**: UI layout and styling
3. **storage.h**: Storage structure and persistence logic

## Future Improvements

Planned enhancements for future versions:

1. **OTA Updates**: Allow firmware updates over WiFi
2. **Multiple AP Profiles**: Support for multiple AP configurations
3. **Advanced Security**: More robust authentication
4. **Energy Monitoring**: Track and optimize power consumption
5. **Mesh Networking**: Support for ESP-NOW or similar protocols

## Limitations

Current known limitations:

1. **Network Count**: Maximum of 5 stored networks
2. **AP Clients**: Maximum of 4 simultaneous connections
3. **EEPROM Writes**: Limited write cycles (approximately 100,000)
4. **WPA3 Support**: Limited based on ESP8266 capabilities 