# AccessPointWiFi Manager

![AccessPointWiFi Manager](https://img.shields.io/badge/IoT-ESP8266-blue) ![Version](https://img.shields.io/badge/Version-1.0.0-green) ![License](https://img.shields.io/badge/License-MIT-orange)

A sleek, modern WiFi configuration manager for ESP8266 devices with an iOS-inspired web interface. This project provides an elegant solution for connecting IoT devices to WiFi networks without hardcoding credentials.

## 📚 Documentation

- [User Guide](docs/usage_guide.md) - Complete instructions for using the WiFi Manager
- [UI/UX Customization](CUSTOMIZATION.md) - Customize the interface to your needs
- [Screenshots Gallery](docs/screenshots.md) - See UI examples and customizations
- [Technical Documentation](DOCUMENTATION.md) - Technical details and architecture
- [Contribution Guide](CONTRIBUTING.md) - How to contribute to the project
- [Changelog](CHANGELOG.md) - Version history and changes

## 🚀 FUEL THE REBELLION!

> **SICK OF BORING WiFi MANAGERS?** So was I. That's why I built this one.
>
> If this project saved your sanity, your time, or just made your day a little better, consider buying me a coffee! Every donation helps keep the rebellion alive and the code flowing.
>
> **[☕ SUPPORT THE REVOLUTION ON TRAKTEER](https://teer.id/haadziq_fatkhiya)**
>
> *Remember: Good WiFi management is an act of rebellion against chaos. Join the cause!*

## ✨ Features

- **Captive Portal**: Automatically redirects to the configuration page when connecting to the AP
- **Network Scanning**: Scans and displays available WiFi networks
- **Multiple Networks**: Stores multiple WiFi credentials for seamless connectivity
- **Connection History**: Tracks connection attempts and success rates
- **Customizable AP**: Configure your own access point name and password
- **Modern UI**: iOS-inspired interface with responsive design
- **Easy UI/UX Customization**: Customize colors, themes, and layout with simple variable changes
- **Theme Support**: Includes light, dark, and Material Design themes out of the box
- **Fallback Mode**: Automatically creates an AP if WiFi connection fails
- **Secure Storage**: Credentials stored in EEPROM

## 📱 User Interface (Local Screenshots & Demo)

### Main Interface (Desktop)

![Main Interface Desktop](docs/screenshots/main interface (dekstop).png)

### Main Interface (Phone)

![Main Interface Phone](docs/screenshots/main interface (phone).png)

### Demo Video

<video src="docs/screenshots/demo.webm" controls width="400"></video>

*The default interface with iOS-inspired design*

## 🛠️ Installation

### Requirements

- ESP8266 board (NodeMCU, Wemos D1 Mini, etc.)
- Arduino IDE 1.8.x or higher
- ESP8266 Board Package (2.7.x or higher)

### Required Libraries

- ESP8266WiFi (included in ESP8266 board package)
- ESP8266WebServer (included in ESP8266 board package)
- EEPROM (included in Arduino IDE)
- ArduinoJson (>=6.0.0)

### Steps

1. Install the ESP8266 board package in Arduino IDE
   - Go to File > Preferences > Additional Board Manager URLs and add:
   ```
   https://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
   - Go to Tools > Board > Boards Manager and install "ESP8266"

2. Install ArduinoJson library
   - Go to Sketch > Include Library > Manage Libraries
   - Search for "ArduinoJson" and install version 6.x

3. Upload the code
   - Connect your ESP8266 board to your computer
   - Select the appropriate board and port in Tools menu
   - Upload the sketch

## 🔧 Usage

![WiFi Manager Usage Flow](https://i.imgur.com/mjT2xYR.png)

### First Connection

1. Power on your ESP8266 device
2. Connect to the "AccessPointWiFi" network (default password: 12345678)
3. Your device should automatically open the configuration portal
   - If not, open a browser and navigate to http://192.168.4.1

### Connecting to WiFi

1. Scan for available networks using the "Scan" button
2. Select your WiFi network from the dropdown list
3. Enter your WiFi password
4. Click "Connect"

### Customizing Access Point

1. Navigate to the "Device Settings" section
2. Click on "Access Point Settings"
3. Enter your desired AP name and password
4. Click "Save"
5. Restart the device to apply changes

For a comprehensive step-by-step guide with screenshots and troubleshooting tips, check our [Detailed Usage Guide](docs/usage_guide.md).

## 📋 Configuration Options

The WiFi Manager can be customized through the following defines in `wifi_manager.h`:

```cpp
// WiFi Configuration
#define AP_SSID "AccessPointWiFi"    // Default AP name
#define AP_PASSWORD "12345678"       // Default AP password
#define AP_CHANNEL 1                 // WiFi channel
#define AP_MAX_CONN 4                // Maximum simultaneous connections

// Timeouts
#define WIFI_CONNECT_TIMEOUT 10000   // Connection timeout (ms)
#define AP_MODE_TIMEOUT 300000       // Auto-disable AP after time (ms)
#define WIFI_CHECK_INTERVAL 15000    // Connection check interval (ms)

// System Configuration
#define MAX_NETWORKS 5               // Maximum stored networks
#define MAX_CONNECT_ATTEMPTS 2       // Connection attempts before fallback
```

## 🎨 UI/UX Customization

AccessPointWiFi Manager comes with an easy-to-use customization system. You can modify the interface to match your brand or preferences without deep technical knowledge.

![UI Customization Examples](https://i.imgur.com/F8qpVNa.png)

### What You Can Customize

- **Colors & Themes**: Change color scheme or use pre-built themes (Light, Dark, Material)
- **Fonts & Typography**: Swap fonts and adjust text sizes
- **Layout & Components**: Modify card arrangements or add new widgets
- **Responsive Behavior**: Adjust how the interface looks on different devices
- **Custom JavaScript**: Add new features or modify existing functionality

### How to Customize

1. Open the `src/web_interface.h` file
2. Locate the CSS variables section (`:root`)
3. Modify the values to match your desired design
4. For more advanced customization, see [CUSTOMIZATION.md](CUSTOMIZATION.md)

For detailed step-by-step instructions and screenshots, check our comprehensive [UI/UX Customization Guide](CUSTOMIZATION.md).

```css
// Example color customization
:root {
  --primary: #FF5722;         // Change primary color to orange
  --primary-light: #FF8A65;   
  --primary-dark: #E64A19;    
  --radius-lg: 24px;          // More rounded corners
}
```

## 🤝 Contributing

Contributions are welcome! Feel free to submit pull requests or open issues.

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 💥 Support This Project

<div align="center">
  
### BREAK THE RULES, CONNECT THE WORLD

This project took countless hours of coding, debugging, and coffee.  
If you found it useful, consider showing some love!

[![Trakteer Me](https://img.shields.io/badge/Trakteer-Support_the_developer-%23F47373?style=for-the-badge&logo=ko-fi)](https://teer.id/haadziq_fatkhiya)

**Your support keeps the rebellion going!**

</div>

## 👨‍💻 Creator

Created by [haadziq](https://teer.id/haadziq_fatkhiya)