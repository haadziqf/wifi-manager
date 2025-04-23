# AccessPointWiFi Manager - Usage Guide

This comprehensive guide explains how to set up, configure, and use the AccessPointWiFi Manager for your ESP8266 device.

## 📱 First-Time Setup

### Step 1: Power On Your Device

1. Connect your ESP8266 device to a power source.
2. Wait for the device to initialize (blue LED will flash briefly).

![Power On Device](https://i.imgur.com/tZWyP5N.jpg)

### Step 2: Connect to the Access Point

1. On your smartphone, tablet, or computer, open the WiFi settings.
2. Look for the network named "AccessPointWiFi" (or your customized AP name if changed).
3. Connect to this network using the default password: `12345678` (or your custom password).

![Connect to AP](https://i.imgur.com/QfPvKrL.png)

### Step 3: Access the Web Interface

1. Open a web browser on your device.
2. Enter the address `http://192.168.4.1` in the address bar.
3. The AccessPointWiFi Manager interface should load.

![Web Interface](https://i.imgur.com/ZkNhTnM.png)

## 🌐 Connecting to WiFi

### Scanning for Networks

1. Click the "Scan" button in the Connect to Network card.
2. Wait a few seconds while the device scans for available networks.
3. A dropdown list will populate with nearby WiFi networks.

![Scanning Networks](https://i.imgur.com/LCWg5mZ.png)

### Connecting to a Network

1. Select your desired WiFi network from the dropdown list.
2. Enter the network password in the password field.
3. Click the "Connect" button.
4. Wait for the connection process to complete.

![Connecting to Network](https://i.imgur.com/mjT2xYR.png)

### Connection Status

After attempting to connect, the status will update to show:
- Success: "Connected to [network]"
- Failure: "Connection failed, falling back to AP mode"

If successfully connected, the status bar will show the connection details and the Monitor Card will display:
- Current SSID
- IP Address
- Signal Strength
- Connection Status
- Uptime

![Connection Status](https://i.imgur.com/QJg9XSB.png)

## 📊 Monitoring & Statistics

### Network Status Monitor

The Network Status card shows real-time information about your connection:

- **SSID**: The name of the connected network
- **IP Address**: Your device's IP address on the network
- **Signal**: Signal strength in dBm (higher is better)
- **Status**: Connection status (Connected/Disconnected)
- **Uptime**: How long the connection has been active

### Connection History

The Connection History card shows:
- Recent connection attempts
- Time of connection
- Success or failure status
- Signal strength at time of connection

This helps you troubleshoot connection issues by showing patterns.

![Connection History](https://i.imgur.com/M8UJeWA.png)

### Network Statistics

The Network Statistics card provides:
- Success rate for each network
- Number of successful connections
- Number of failed connections
- Overall reliability metrics

Use this to identify problematic networks or connection patterns.

## ⚙️ Device Settings

### Customizing the Access Point

1. Scroll down to the Device Settings card.
2. Click on "Access Point Settings".
3. A modal window will appear with settings.

![AP Settings Modal](https://i.imgur.com/P5TnSRO.png)

4. Enter your desired Access Point Name (SSID).
5. Enter a new password or leave blank to keep the existing one.
6. Click "Save".
7. A message will indicate that settings were saved.
8. Restart the device to apply the new AP settings.

## 🔍 Advanced Features

### Multiple Network Management

The device stores up to 5 network credentials. When powered on, it will:
1. Attempt to connect to the last successful network.
2. If that fails, try other stored networks in order.
3. Fall back to AP mode if all connection attempts fail.

### Automatic Reconnection

If the WiFi connection drops:
1. The device will automatically attempt to reconnect.
2. If reconnection fails after 2 attempts, it will:
   - Fall back to AP mode
   - Continue trying to reconnect periodically

### Signal Strength Indicators

The signal strength is displayed in both:
- Numerical form (dBm)
- Visual form (bars) in the network selection dropdown

Generally:
- -50 to -60 dBm: Excellent
- -60 to -70 dBm: Good
- -70 to -80 dBm: Fair
- -80 to -90 dBm: Poor

## 🔄 Updating the Device

### Firmware Updates

To update the firmware:
1. Download the latest firmware from the repository.
2. Connect the ESP8266 device to your computer.
3. Use the Arduino IDE or similar tool to upload the new firmware.
4. After updating, reset the device.

## 🛠️ Troubleshooting

### Device Won't Create Access Point

**Solution:**
1. Reset the device by pressing the reset button.
2. Check power connection - ensure stable power supply.
3. If problem persists, try flashing the firmware again.

### Can't Connect to WiFi Network

**Solutions:**
1. Verify correct password entry.
2. Check if the network is within range.
3. Verify the network supports the ESP8266 (2.4GHz, compatible security).
4. Try rebooting your router.

### Web Interface Doesn't Load

**Solutions:**
1. Verify you're connected to the correct AP network.
2. Try a different browser.
3. Clear browser cache.
4. Check that you're using the correct IP address (http://192.168.4.1).

### Device Frequently Disconnects

**Solutions:**
1. Check signal strength - move closer to router if poor.
2. Ensure stable power supply.
3. Check router settings - some routers disconnect inactive clients.
4. Update to the latest firmware.

## 📱 Mobile Usage Tips

### iOS Devices

- iOS may prompt "This network has no internet connection." This is normal.
- Select "Use Without Internet" or similar option.
- If the captive portal doesn't appear automatically, open Safari and navigate to http://192.168.4.1.

### Android Devices

- Android may show "Internet may not be available." This is normal.
- Tap "Yes" to stay connected.
- If the captive portal doesn't appear, open Chrome and navigate to http://192.168.4.1.

## 🔒 Security Considerations

- Change the default AP password immediately after setup.
- Use strong passwords for both AP and WiFi networks.
- The device stores passwords in EEPROM, which is not encrypted by default.
- For critical applications, consider implementing additional security measures.

## Need More Help?

If you encounter issues not covered in this guide, please:
1. Check the [GitHub repository](https://github.com/username/wifi-manager) for updates.
2. Open an issue with detailed information about your problem.
3. Review the [Technical Documentation](../DOCUMENTATION.md) for advanced information. 