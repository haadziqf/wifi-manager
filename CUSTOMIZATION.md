# UI/UX Customization Guide

This guide explains how to easily customize the look and feel of your AccessPointWiFi Manager. You can modify colors, styles, layout, and behavior without deep technical knowledge.

## 📸 Screenshots

To see examples of different UI/UX customizations, check out the [Screenshots Gallery](docs/screenshots.md).

## 🔍 Understanding the Interface

The WiFi Manager interface consists of several key components:

![Interface Components](https://i.imgur.com/A5TYHLr.png)

1. **Header Bar**: Contains the logo and title
2. **Status Bar**: Shows the current connection status
3. **Connect Card**: For scanning and connecting to networks
4. **Monitor Card**: Shows details about the current connection
5. **History Card**: Displays connection history
6. **Stats Card**: Shows network statistics
7. **Settings Card**: Access to device settings
8. **Footer Bar**: Shows IP address and refresh button

Each component can be individually customized or completely replaced.

## 🎨 Quick Customization

The WiFi Manager is designed with ease of customization in mind. You can quickly change the appearance by modifying the CSS variables at the beginning of the `web_interface.h` file.

### Changing Colors

1. Open `src/web_interface.h`
2. Locate the `:root` section in the CSS (around line 50)
3. Modify the color variables:

```css
:root {
    --primary: #007AFF;       /* Main accent color */
    --primary-light: #4DA3FF; /* Lighter version of accent */
    --primary-dark: #0055B3;  /* Darker version of accent */
    --success: #34C759;       /* Success message color */
    --danger: #FF3B30;        /* Error/warning color */
    --warning: #FF9500;       /* Warning message color */
    /* Additional color variables... */
}
```

For example, to change to a purple theme:

```css
:root {
    --primary: #8E44AD;       /* Purple */
    --primary-light: #9B59B6; /* Light purple */
    --primary-dark: #7D3C98;  /* Dark purple */
    /* Other colors... */
}
```

### Changing Fonts

```css
:root {
    /* ... */
    --font-sans: 'Your Preferred Font', -apple-system, BlinkMacSystemFont, "SF Pro Text", sans-serif;
    /* ... */
}
```

For example, to use Google Fonts:

1. Add the Google Fonts link to the HTML_HEAD_END section:
```html
const char HTML_HEAD_END[] PROGMEM = R"rawliteral(
    </title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=0">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="default">
    <meta name="theme-color" content="#007AFF">
    <link rel="apple-touch-icon" href="data:image/svg+xml;base64,...">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@400;500;600&display=swap" rel="stylesheet">
    <style>
)rawliteral";
```

2. Then update the font variable:
```css
:root {
    /* ... */
    --font-sans: 'Poppins', sans-serif;
    /* ... */
}
```

### Changing Sizes and Spacing

```css
:root {
    /* ... */
    --radius-sm: 8px;        /* Small border radius */
    --radius-md: 12px;       /* Medium border radius */
    --radius-lg: 16px;       /* Large border radius */
    /* ... */
}
```

For more rounded corners:
```css
:root {
    /* ... */
    --radius-sm: 12px;
    --radius-md: 18px;
    --radius-lg: 24px;
    /* ... */
}
```

## 🧩 Theme Presets

For quick styling, you can replace the entire `:root` section with one of these presets:

### Dark Mode Theme
```css
:root {
    --primary: #0A84FF;
    --primary-light: #5AC8FA;
    --primary-dark: #0055B3;
    --success: #30D158;
    --danger: #FF453A;
    --warning: #FFD60A;
    --gray-50: #1C1C1E;
    --gray-100: #2C2C2E;
    --gray-200: #3A3A3C;
    --gray-300: #48484A;
    --gray-400: #636366;
    --gray-500: #8E8E93;
    --gray-600: #AEAEB2;
    --gray-700: #C7C7CC;
    --gray-800: #E5E5EA;
    --gray-900: #F2F2F7;
    /* ...other variables... */
}

/* Add this to enable dark mode */
body {
    background: var(--gray-100);
    color: var(--gray-800);
}
.card {
    background: var(--gray-200);
    border-color: var(--gray-300);
}
.header {
    background-color: rgba(58, 58, 60, 0.8);
}
#status-bar {
    background: rgba(58, 58, 60, 0.8);
}
#ip-display {
    background: rgba(58, 58, 60, 0.8);
}
input, select {
    background: var(--gray-300);
    color: var(--gray-800);
    border-color: var(--gray-400);
}
/* ...additional dark mode overrides... */
```

See the [Dark Mode Screenshot](docs/screenshots.md#dark-mode-theme) for an example.

### Material Design Theme
```css
:root {
    --primary: #6200EE;
    --primary-light: #BB86FC;
    --primary-dark: #3700B3;
    --secondary: #03DAC6;
    --secondary-dark: #018786;
    --success: #00C853;
    --danger: #B00020;
    --warning: #FFAB00;
    --radius-sm: 4px;
    --radius-md: 8px;
    --radius-lg: 12px;
    --font-sans: 'Roboto', sans-serif;
    /* ...other variables... */
}
```

See the [Material Design Screenshot](docs/screenshots.md#material-design-theme) for an example.

## 🔧 Step-by-Step Usage Guide

### First Time Setup

1. **Connect to the Access Point**
   - Power on your ESP8266 device
   - Connect to the "AccessPointWiFi" network (default password: 12345678)
   - Open a browser and navigate to http://192.168.4.1

2. **Scan for Networks**
   - Click the "Scan" button to find available WiFi networks
   - Select your network from the dropdown list

3. **Connect to Your Network**
   - Enter your WiFi password
   - Click "Connect"
   - Wait for connection confirmation

### Managing Saved Networks

1. View saved networks by checking the connection history card
2. Connect to a previously saved network by selecting it from the dropdown
3. The device will automatically try to connect to saved networks when powered on

### Customizing Access Point Settings

1. Scroll down to the "Device Settings" card
2. Click on "Access Point Settings"
3. Enter your desired AP name and password
4. Click "Save"
5. Restart the device to apply changes

### Monitoring Connection Status

The "Network Status" card shows:
- Current SSID
- IP address
- Signal strength
- Connection status
- Uptime

## 🏗️ Advanced Customization

### Custom Card Components

You can modify the HTML structure for each card in the interface:

1. Locate the card definitions in `web_interface.h`:
   - `HTML_CONNECT_CARD_START`
   - `HTML_MONITOR_CARD`
   - `HTML_HISTORY_CARD`
   - etc.

2. Edit the HTML structure as needed, keeping the same ID attributes for JavaScript functionality.

Example:
```html
const char HTML_MONITOR_CARD[] PROGMEM = R"rawliteral(
    <div class='card monitor-card custom-monitor' id='monitor-card'>
        <div class='card-header my-custom-header'>
            <h2>Network Status</h2>
        </div>
        <div class='monitor-content'>
            <!-- Your customized layout -->
            <div class='monitor-item'><strong>SSID</strong> <span id='mon-ssid'>-</span></div>
            <!-- Keep the IDs (mon-ssid, etc.) the same for JS functionality -->
        </div>
    </div>
)rawliteral";
```

### Custom JavaScript Functions

You can extend or override the JavaScript functionality:

1. Locate the JS_SCRIPT section
2. Add your custom functions or override existing ones

Example - Extending the status update with a custom animation:
```javascript
// Original function (keep this)
function updateStatus() {
    // ...existing code...
}

// Your custom extension
const originalUpdateStatus = updateStatus;
updateStatus = function() {
    // Call the original function
    originalUpdateStatus();
    
    // Add your custom behavior
    const status = document.getElementById('status-bar');
    status.classList.add('status-updated');
    setTimeout(() => {
        status.classList.remove('status-updated');
    }, 1000);
};

// Add your custom status-updated animation
const style = document.createElement('style');
style.innerHTML = `
.status-updated {
    animation: pulse 1s ease;
}
`;
document.head.appendChild(style);
```

### Custom Layouts

For major layout changes, you can modify the main HTML structure by editing the HTML template parts:

1. `HTML_HEAD_START`
2. `HTML_BODY_START`
3. `HTML_BODY_CONTINUE`
4. etc.

## 🔄 Adding Custom Pages

You can add completely new pages to the interface:

1. Define a new HTML template for your page in `web_interface.h`
2. Add a new route in `setupWebServer()` function in `wifi_manager.cpp`:

```cpp
void WiFiManager::setupWebServer() {
    // ...existing routes...
    server.on("/my-custom-page", HTTP_GET, [this]() { handleCustomPage(); });
}

void WiFiManager::handleCustomPage() {
    server.send(200, "text/html", CUSTOM_PAGE_TEMPLATE);
}
```

## 📊 Adding Custom Widgets

To add a new widget to the dashboard:

1. Create the HTML for your widget
2. Add the corresponding JavaScript functionality
3. Insert it into the appropriate section in the main interface

Example - Adding a CPU temperature widget:
```html
const char HTML_TEMP_WIDGET[] PROGMEM = R"rawliteral(
    <div class='card'>
        <div class='card-header'>
            <h2>CPU Temperature</h2>
        </div>
        <div class='monitor-content'>
            <div class='monitor-item'>
                <strong>Current</strong> 
                <span id='cpu-temp'>--°C</span>
            </div>
        </div>
    </div>
)rawliteral";
```

Add it to the main HTML flow after another card:
```cpp
server.sendContent_P(HTML_MONITOR_CARD);
server.sendContent_P(HTML_TEMP_WIDGET);  // Your new widget
server.sendContent_P(HTML_HISTORY_CARD);
```

Add the JavaScript to update it:
```javascript
// Add to the JS_SCRIPT section
function updateCpuTemp() {
    fetch('/cpu-temp')
        .then(response => response.json())
        .then(data => {
            document.getElementById('cpu-temp').textContent = data.temperature + '°C';
        })
        .catch(error => {
            console.error('Error fetching CPU temperature:', error);
        });
}

// Call it periodically
setInterval(updateCpuTemp, 5000);
```

See the [Custom Widget Screenshot](docs/screenshots.md#custom-widgets) for an example.

## 🧪 Customization Tips

1. **Test incrementally**: Make small changes and test them before moving on
2. **Back up your files**: Save a copy of original files before modifying
3. **Use browser dev tools**: Test CSS changes in your browser before updating the code
4. **Watch memory usage**: ESP8266 has limited memory, so keep HTML/CSS lean
5. **Maintain IDs**: Keep the original ID attributes for JavaScript functionality

## 📱 Responsive Design Customization

The interface is already responsive, but you can customize the responsive behavior:

```css
/* Modify these sections in the CSS_STYLES constant */
@media (min-width: 768px) {
    /* Your custom styles for larger screens */
    .card {
        max-width: 700px; /* Make cards wider */
    }
    
    .monitor-content {
        grid-template-columns: 1fr 1fr 1fr; /* Three columns instead of two */
    }
}
```

See the [Responsive Design Screenshots](docs/screenshots.md#responsive-design) for examples across different devices.

## 🌈 Complete UI Replacement

For a complete UI replacement while maintaining functionality:

1. Create your own HTML/CSS/JS files
2. Replace the entire content of the send functions in `handleRoot()`
3. Ensure all API endpoints are called correctly in your custom JavaScript
4. Keep the right ID attributes that are referenced by existing JavaScript

The API endpoints your custom UI should use:
- GET `/scan` - Scan for WiFi networks
- POST `/connect` - Connect to a WiFi network
- GET `/status` - Get connection status
- GET `/history` - Get connection history
- POST `/ap-settings` - Update AP settings
- GET `/get-ap-settings` - Get current AP settings

## 🪲 Troubleshooting Common Customization Issues

### Interface Doesn't Show Changes

1. **Clear Browser Cache**: Use Ctrl+F5 or clear your browser cache
2. **Check File Upload**: Ensure your modified files were uploaded correctly
3. **Syntax Errors**: Check for missing brackets or quotes in your CSS/HTML

### JavaScript Errors

1. **Check Browser Console**: Use F12 to open developer tools and check for errors
2. **ID Consistency**: Ensure you haven't changed ID attributes used by JavaScript
3. **API Endpoints**: Make sure you're using the correct API endpoints

### Memory Issues

1. **Minimize HTML/CSS**: Keep your customizations lean
2. **Remove Unused Features**: Comment out parts you don't need
3. **Compress Images**: Use data URIs sparingly

## Need More Help?

For more advanced customization, check the project's GitHub repository or open an issue with your specific customization needs.

Happy customizing! 🎨✨ 