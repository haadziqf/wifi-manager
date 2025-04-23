#ifndef WEB_INTERFACE_H
#define WEB_INTERFACE_H

// Chunked HTML Template Parts
const char HTML_HEAD_START[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <title>
)rawliteral";

// TITLE is sent dynamically

const char HTML_HEAD_END[] PROGMEM = R"rawliteral(
    </title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=0">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="default">
    <meta name="theme-color" content="#007AFF">
    <link rel="apple-touch-icon" href="data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAyNTYgMjU2Ij48cmVjdCB3aWR0aD0iMjU2IiBoZWlnaHQ9IjI1NiIgZmlsbD0iIzAwN2FmZiIgcng9IjY0Ii8+PHBhdGggZmlsbD0id2hpdGUiIGQ9Ik0xMjggMTgwYTUyIDUyIDAgMSAwIDAtMTA0IDUyIDUyIDAgMCAwIDAgMTA0em01NC4zLTU3LjFhNzYuNCA3Ni40IDAgMCAxLTE1LjEgNDUuNyA3NC41IDc0LjUgMCAwIDEtNDkuNSAzMC44IDc4LjUgNzguNSAwIDAgMS00OS44LTE1LjNjLTIuOS0yLTMuNS02LjEtMS4zLTguOCA1LjktNyAxMy43LTExLjggMjIuNC0xMy45LjYtLjkgMS4xLTEuOCAxLjQtMi43IDItNi4zLS44LTEzLjYtNS43LTE2LjggMS40LTIuNSAzLjItNC43IDUuNC02LjQgMTEuMi04LjggMjcuMS04LjggMzguNSAwIDIgMS42IDMuOCAzLjkgNS4xIDYuNC00LjggMy4yLTcuNiAxMC4zLTUuNSAxNi41LjQuOSAxIDEuOCAxLjYgMi43IDguNiAyLjIgMTYuNCA3IDE4LjEgMTQgMi4xIDIuNyAxLjYgNi43LTEuMyA4LjhoLjFhNzcgNzcgMCAwIDEtNDkuOCAxNS4yIDE4LjYgMTguNiAwIDAgMS0xOC42LTE4LjdjMC0xMC4zIDguNC0xOC43IDE4LjYtMTguN2ExOC42IDE4LjYgMCAwIDEgMTguNyAxOC43YzAgMi4zLS41IDQuNS0xLjMgNi42bC4xLjFhMTcuOCAxNy44IDAgMSAwLTM0LjUtLjFsLjEtLjFjLS44LTItMS40LTQuNC0xLjMtNi41LjktMjUuNSAyMS45LTQ1LjkgNDcuNS00Ni4zIDI3LS40IDQ5LjIgMjEuNSA0OS4yIDQ4LjR2LS4xeiIvPjwvc3ZnPg==">
    <style>
)rawliteral";

// CSS_STYLES is sent here

const char HTML_BODY_START[] PROGMEM = R"rawliteral(
    </style>
</head>
<body>
    <div class='header'>
        <div class='wifi-icon'>
            <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" width="32" height="32">
                <path d="M12 16c-1.1 0-2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2zm-6.34-1c-.55 0-.79.67-.4 1.04 2.03 1.79 4.61 2.96 7.47 3.17.74.05 1.27-.73.9-1.41-.57-1.06-1.04-2.19-1.36-3.37-.14-.53-.74-.83-1.27-.7-1.98.49-3.75 1.29-5.34 2.27zm12.69 0c-1.59-.98-3.36-1.78-5.34-2.27-.54-.13-1.13.17-1.27.7-.32 1.17-.79 2.31-1.36 3.37-.37.68.16 1.46.9 1.41 2.86-.21 5.44-1.38 7.47-3.17.39-.37.15-1.04-.4-1.04z M1.61 7.79c-.55 0-.79.67-.4 1.04 4.3 3.8 9.8 6.17 15.85 6.38.74.05 1.27-.73.9-1.41-.57-1.06-1.04-2.19-1.36-3.37-.14-.53-.74-.83-1.27-.7-5.07 1.24-9.32 3.02-13.72 6.06zm20.79 0c-4.4-3.04-8.65-4.82-13.72-6.06-.54-.13-1.13.17-1.27.7-.32 1.17-.79 2.31-1.36 3.37-.37.68.16 1.46.9 1.41 6.05-.21 11.55-2.58 15.85-6.38.39-.37.15-1.04-.4-1.04z"/>
            </svg>
        </div>
        <div class="header-text">
            <h1>
)rawliteral";

// TITLE is sent here again for H1

const char HTML_BODY_CONTINUE[] PROGMEM = R"rawliteral(
            </h1>
            <p class="header-subtitle">Smart Wireless Network Manager</p>
        </div>
    </div>
    <div id='status-bar'>Initializing...</div>
)rawliteral";

const char HTML_CONNECT_CARD_START[] PROGMEM = R"rawliteral(
    <div class='card'>
        <div class='card-header'>
            <div class='card-icon'>
                <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M8.288 15.038a5.25 5.25 0 017.424 0M5.106 11.856c3.807-3.808 9.98-3.808 13.788 0M1.924 8.674c5.565-5.565 14.587-5.565 20.152 0M12.53 18.22l-.53.53-.53-.53a.75.75 0 011.06 0z" />
                </svg>
            </div>
            <h2>Connect to Network</h2>
        </div>
)rawliteral";

// CONTENT_TEMPLATE is sent here

const char HTML_CONNECT_CARD_END[] PROGMEM = R"rawliteral(
    </div>
)rawliteral";

// New Monitor Card Definition
const char HTML_MONITOR_CARD[] PROGMEM = R"rawliteral(
    <div class='card monitor-card' id='monitor-card' style='display: none;'>
        <div class='card-header'>
             <div class='card-icon'>
                <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M9 17.25v1.007a3 3 0 01-.879 2.122L7.5 21h9l-.621-.621A3 3 0 0115 18.257V17.25m6-12V15a2.25 2.25 0 01-2.25 2.25H5.25A2.25 2.25 0 013 15V5.25m18 0A2.25 2.25 0 0018.75 3H5.25A2.25 2.25 0 003 5.25m18 0V12a2.25 2.25 0 01-2.25 2.25H5.25A2.25 2.25 0 013 12V5.25" />
                </svg>
             </div>
            <h2>Network Status</h2>
        </div>
        <div class='monitor-content'>
            <div class='monitor-item'><strong>SSID</strong> <span id='mon-ssid'>-</span></div>
            <div class='monitor-item'><strong>IP Address</strong> <span id='mon-ip'>-</span></div>
            <div class='monitor-item'><strong>Signal</strong> <span id='mon-rssi'>-</span></div>
            <div class='monitor-item'><strong>Status</strong> <span id='mon-status'>-</span></div>
            <div class='monitor-item'><strong>Uptime</strong> <span id='mon-uptime'>-</span></div>
        </div>
    </div>
)rawliteral";

const char HTML_HISTORY_CARD[] PROGMEM = R"rawliteral(
    <div class='card'>
        <div class='card-header'>
             <div class='card-icon'>
                <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M12 6v6h4.5m4.5 0a9 9 0 11-18 0 9 9 0 0118 0z" />
                </svg>
             </div>
            <h2>Connection History</h2>
        </div>
        <div id="connection-history" class="log-content">Loading history...</div>
    </div>
)rawliteral";

const char HTML_STATS_CARD[] PROGMEM = R"rawliteral(
    <div class='card'>
        <div class='card-header'>
            <div class='card-icon'>
                <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M3 13.125C3 12.504 3.504 12 4.125 12h2.25c.621 0 1.125.504 1.125 1.125v6.75C7.5 20.496 6.996 21 6.375 21h-2.25A1.125 1.125 0 013 19.875v-6.75zM9.75 8.625c0-.621.504-1.125 1.125-1.125h2.25c.621 0 1.125.504 1.125 1.125v11.25c0 .621-.504 1.125-1.125 1.125h-2.25a1.125 1.125 0 01-1.125-1.125V8.625zM16.5 4.125c0-.621.504-1.125 1.125-1.125h2.25C20.496 3 21 3.504 21 4.125v15.75c0 .621-.504 1.125-1.125 1.125h-2.25a1.125 1.125 0 01-1.125-1.125V4.125z" />
                </svg>
            </div>
            <h2>Network Statistics</h2>
        </div>
        <div id="network-stats" class="log-content">Loading stats...</div>
    </div>
)rawliteral";

const char HTML_SETTINGS_CARD[] PROGMEM = R"rawliteral(
    <div class='card'>
        <div class='card-header'>
            <div class='card-icon'>
                <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M9.594 3.94c.09-.542.56-.94 1.11-.94h2.593c.55 0 1.02.398 1.11.94l.213 1.281c.063.374.313.686.645.87.074.04.147.083.22.127.324.196.72.257 1.075.124l1.217-.456a1.125 1.125 0 011.37.49l1.296 2.247a1.125 1.125 0 01-.26 1.431l-1.003.827c-.293.24-.438.613-.431.992a6.759 6.759 0 010 .255c-.007.378.138.75.43.99l1.005.828c.424.35.534.954.26 1.43l-1.298 2.247a1.125 1.125 0 01-1.369.491l-1.217-.456c-.355-.133-.75-.072-1.076.124a6.57 6.57 0 01-.22.128c-.331.183-.581.495-.644.869l-.213 1.28c-.09.543-.56.941-1.11.941h-2.594c-.55 0-1.02-.398-1.11-.94l-.213-1.281c-.062-.374-.312-.686-.644-.87a6.52 6.52 0 01-.22-.127c-.325-.196-.72-.257-1.076-.124l-1.217.456a1.125 1.125 0 01-1.369-.49l-1.297-2.247a1.125 1.125 0 01.26-1.431l1.004-.827c.292-.24.437-.613.43-.992a6.932 6.932 0 010-.255c.007-.378-.138-.75-.43-.99l-1.004-.828a1.125 1.125 0 01-.26-1.43l1.297-2.247a1.125 1.125 0 011.37-.491l1.216.456c.356.133.751.072 1.076-.124.072-.044.146-.087.22-.128.332-.183.582-.495.644-.869l.214-1.281z" />
                    <path stroke-linecap="round" stroke-linejoin="round" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
                </svg>
            </div>
            <h2>Device Settings</h2>
        </div>
        <div class='setting-row'>
            <div class='setting-icon'>
                <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M9.348 14.651a3.75 3.75 0 010-5.303m5.304 0a3.75 3.75 0 010 5.303m-7.425 2.122a6.75 6.75 0 010-9.546m9.546 0a6.75 6.75 0 010 9.546M5.106 18.894c-3.808-3.808-3.808-9.98 0-13.789m13.788 0c3.808 3.808 3.808 9.981 0 13.79M12 12h.008v.007H12V12zm.375 0a.375.375 0 11-.75 0 .375.375 0 01.75 0z" />
                </svg>
            </div>
            <a href="#" class="settings-link" onclick="showApSettings()">Access Point Settings</a>
        </div>
    </div>
)rawliteral";

const char HTML_FOOTER[] PROGMEM = R"rawliteral(
    <div id="ip-display">
        <span id="ip-address">Connecting...</span>
        <span id="creator-info">Created by <a href="https://teer.id/haadziq_fatkhiya" target="_blank" rel="noopener">haadziq</a></span>
        <button id="refresh-btn" onclick="location.reload()" aria-label="Refresh">
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" d="M16.023 9.348h4.992v-.001M2.985 19.644v-4.992m0 0h4.992m-4.993 0l3.181 3.183a8.25 8.25 0 0013.803-3.7M4.031 9.865a8.25 8.25 0 0113.803-3.7l3.181 3.182m0-4.991v4.99" />
            </svg>
        </button>
    </div>
)rawliteral";

const char HTML_MODAL[] PROGMEM = R"rawliteral(
    <div id="ap-settings-modal" class="modal">
        <div class="modal-content">
            <div class="modal-header">
                <h2>Access Point Settings</h2>
                <span class="close" onclick="closeModal()">&times;</span>
            </div>
            <div class="modal-body">
                <div class="input-group">
                    <label for="ap-ssid">AP Name (SSID)</label>
                    <input type="text" id="ap-ssid" placeholder="Enter AP name">
                </div>
                <div class="input-group">
                    <label for="ap-password">AP Password</label>
                    <input type="password" id="ap-password" placeholder="Enter AP password">
                </div>
                <div class="button-row">
                    <button class="cancel-btn" onclick="closeModal()">Cancel</button>
                    <button class="save-btn" onclick="saveApSettings()">Save</button>
                </div>
            </div>
        </div>
    </div>
)rawliteral";

const char HTML_SCRIPT_START[] PROGMEM = R"rawliteral(
    <script>
)rawliteral";

// JS_SCRIPT is sent here

const char HTML_SCRIPT_END[] PROGMEM = R"rawliteral(
    </script>
</body>
</html>
)rawliteral";

// Stylesheet - New modern design
const char CSS_STYLES[] PROGMEM = R"rawliteral(
/* Base Styles */
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    -webkit-tap-highlight-color: transparent;
}

:root {
    --primary: #007AFF;
    --primary-light: #4DA3FF;
    --primary-dark: #0055B3;
    --success: #34C759;
    --danger: #FF3B30;
    --warning: #FF9500;
    --gray-50: #F9F9F9;
    --gray-100: #F2F2F7;
    --gray-200: #E5E5EA;
    --gray-300: #D1D1D6;
    --gray-400: #C7C7CC;
    --gray-500: #AEAEB2;
    --gray-600: #8E8E93;
    --gray-700: #636366;
    --gray-800: #3A3A3C;
    --gray-900: #1C1C1E;
    --radius-sm: 8px;
    --radius-md: 12px;
    --radius-lg: 16px;
    --shadow-sm: 0 1px 2px rgba(0, 0, 0, 0.05);
    --shadow-md: 0 4px 8px rgba(0, 0, 0, 0.07);
    --shadow-lg: 0 12px 24px rgba(0, 0, 0, 0.09);
    --font-sans: -apple-system, BlinkMacSystemFont, "SF Pro Text", "SF Pro Icons", "Helvetica Neue", Helvetica, Arial, sans-serif;
}

body {
    font-family: var(--font-sans);
    background: var(--gray-100);
    color: var(--gray-800);
    line-height: 1.5;
    padding-bottom: 80px;
    font-size: 16px;
    overflow-x: hidden;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
}

h1, h2, h3, h4 {
    font-weight: 600;
    color: var(--gray-900);
    letter-spacing: -0.01em;
    line-height: 1.2;
}

/* Header - iOS style */
.header {
    background-color: rgba(255, 255, 255, 0.8);
    backdrop-filter: blur(10px);
    -webkit-backdrop-filter: blur(10px);
    box-shadow: 0 1px 0 rgba(0, 0, 0, 0.05);
    padding: 16px 24px;
    display: flex;
    align-items: center;
    position: sticky;
    top: 0;
    z-index: 100;
}

.wifi-icon {
    margin-right: 16px;
    display: flex;
    align-items: center;
    justify-content: center;
}

.wifi-icon svg {
    fill: var(--primary);
    width: 28px;
    height: 28px;
}

.header-text {
    display: flex;
    flex-direction: column;
}

.header h1 {
    font-size: 22px;
    color: var(--primary);
    font-weight: 700;
    margin-bottom: 2px;
    line-height: 1.1;
}

.header-subtitle {
    font-size: 14px;
    color: var(--gray-500);
    font-weight: 400;
}

/* Status Bar - iOS style */
#status-bar {
    padding: 10px 24px;
    background: rgba(255, 255, 255, 0.8);
    backdrop-filter: blur(8px);
    -webkit-backdrop-filter: blur(8px);
    color: var(--gray-600);
    font-size: 14px;
    font-weight: 500;
    border-bottom: 1px solid var(--gray-200);
    transition: all 0.2s ease;
    display: flex;
    align-items: center;
    gap: 8px;
    position: sticky;
    top: 62px;
    z-index: 90;
}

#status-bar:before {
    content: '';
    display: inline-block;
    width: 8px;
    height: 8px;
    border-radius: 50%;
    background-color: var(--primary);
    margin-right: 8px;
}

/* Cards - iOS style */
.card {
    background: white;
    border-radius: var(--radius-lg);
    margin: 16px;
    box-shadow: var(--shadow-md);
    overflow: hidden;
    transition: all 0.3s ease;
    border: 1px solid var(--gray-200);
    position: relative;
}

.card:hover {
    transform: translateY(-2px);
    box-shadow: var(--shadow-lg);
}

.card-header {
    padding: 18px 20px;
    display: flex;
    align-items: center;
    border-bottom: 1px solid var(--gray-200);
}

.card-icon {
    margin-right: 14px;
    display: flex;
    align-items: center;
    justify-content: center;
    background-color: var(--gray-100);
    height: 36px;
    width: 36px;
    border-radius: 50%;
}

.card-icon svg {
    width: 20px;
    height: 20px;
    stroke: var(--primary);
}

.card-header h2 {
    font-size: 17px;
    margin: 0;
    font-weight: 600;
    color: var(--gray-800);
}

/* Form Elements - iOS style */
.form-group {
    padding: 18px 20px;
    border-bottom: 1px solid var(--gray-200);
}

.form-group:last-child {
    border-bottom: none;
}

.form-group label {
    display: block;
    margin-bottom: 8px;
    color: var(--gray-700);
    font-size: 15px;
    font-weight: 500;
}

.select-wrapper, .input-wrapper {
    position: relative;
}

input, select, button {
    width: 100%;
    padding: 12px 16px;
    border: 1px solid var(--gray-300);
    border-radius: var(--radius-md);
    font-size: 16px;
    background: white;
    transition: all 0.2s ease;
    outline: none;
    color: var(--gray-800);
    -webkit-appearance: none;
    appearance: none;
}

.input-wrapper input {
    padding-right: 46px;
}

input:focus, select:focus {
    border-color: var(--primary);
    box-shadow: 0 0 0 3px rgba(0, 122, 255, 0.15);
}

input::placeholder {
    color: var(--gray-500);
}

select {
    background-image: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="%238E8E93" stroke-width="2"><path stroke-linecap="round" stroke-linejoin="round" d="M19 9l-7 7-7-7" /></svg>');
    background-repeat: no-repeat;
    background-position: right 14px center;
    background-size: 16px;
    padding-right: 42px;
}

/* Buttons - iOS style */
button {
    background: var(--primary);
    color: white;
    border: none;
    font-weight: 600;
    cursor: pointer;
    transition: all 0.2s ease;
    display: flex;
    align-items: center;
    justify-content: center;
    gap: 8px;
    border-radius: var(--radius-md);
    font-size: 16px;
    height: 44px;
    padding: 0 20px;
    text-align: center;
}

button:hover {
    background: var(--primary-light);
}

button:active {
    transform: scale(0.98);
    background: var(--primary-dark);
}

button svg {
    width: 18px;
    height: 18px;
}

/* Settings */
.setting-row {
    padding: 16px 24px;
    display: flex;
    align-items: center;
    border-bottom: 1px solid var(--gray-200);
    transition: background-color 0.15s ease;
}

.setting-row:hover {
    background-color: var(--gray-50);
}

.setting-icon {
    margin-right: 16px;
    display: flex;
    align-items: center;
    justify-content: center;
    height: 36px;
    width: 36px;
    border-radius: 50%;
    background-color: var(--gray-100);
}

.setting-icon svg {
    width: 18px;
    height: 18px;
    fill: var(--primary);
}

.settings-link {
    color: var(--gray-700);
    text-decoration: none;
    font-size: 15px;
    font-weight: 500;
    transition: color 0.15s ease;
    display: flex;
    align-items: center;
    justify-content: space-between;
    width: 100%;
}

.settings-link:after {
    content: '';
    display: inline-block;
    width: 16px;
    height: 16px;
    background-image: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="%236b7280" stroke-width="2"><path stroke-linecap="round" stroke-linejoin="round" d="M9 5l7 7-7 7" /></svg>');
    background-repeat: no-repeat;
    background-position: center;
    background-size: contain;
}

.settings-link:hover {
    color: var(--primary);
}

/* IP Display */
#ip-display {
    position: fixed;
    bottom: 0;
    left: 0;
    width: 100%;
    display: flex;
    align-items: center;
    justify-content: space-between;
    padding: 16px 24px;
    background: white;
    border-top: 1px solid var(--gray-200);
    box-shadow: var(--shadow-md);
    z-index: 100;
}

#ip-address {
    font-size: 14px;
    color: var(--gray-700);
    font-weight: 500;
    display: flex;
    align-items: center;
    gap: 8px;
}

#ip-address:before {
    content: '';
    display: inline-block;
    width: 10px;
    height: 10px;
    background-image: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="%236b7280" stroke-width="2"><path stroke-linecap="round" stroke-linejoin="round" d="M21 12a9 9 0 01-9 9m9-9a9 9 0 00-9-9m9 9H3m9 9a9 9 0 01-9-9m9 9c1.657 0 3-4.03 3-9s-1.343-9-3-9m0 18c-1.657 0-3-4.03-3-9s1.343-9 3-9m-9 9a9 9 0 019-9" /></svg>');
    background-repeat: no-repeat;
    background-position: center;
    background-size: contain;
}

#creator-info {
    font-size: 13px;
    color: var(--gray-600);
    display: flex;
    align-items: center;
    gap: 6px;
}

#creator-info a {
    color: var(--primary);
    text-decoration: none;
    font-weight: 500;
    transition: color 0.15s ease;
}

#creator-info a:hover {
    color: var(--primary-dark);
    text-decoration: underline;
}

#refresh-btn {
    width: 40px;
    height: 40px;
    min-width: 40px;
    padding: 8px;
    border-radius: 50%;
    background: var(--gray-100);
    color: var(--gray-700);
    transition: all 0.15s ease;
}

#refresh-btn:hover {
    background: var(--primary-light);
    color: white;
}

/* Modal */
.modal {
    display: none;
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: rgba(0, 0, 0, 0.4);
    backdrop-filter: blur(4px);
    z-index: 200;
    animation: fadeIn 0.2s ease;
}

@keyframes fadeIn {
    from { opacity: 0; }
    to { opacity: 1; }
}

.modal-content {
    background: white;
    border-radius: var(--radius-lg);
    margin: 80px auto;
    max-width: 480px;
    width: calc(100% - 40px);
    overflow: hidden;
    box-shadow: var(--shadow-lg);
    animation: slideIn 0.25s ease;
    transform-origin: top center;
}

@keyframes slideIn {
    from { 
        opacity: 0;
        transform: translateY(-20px) scale(0.95);
    }
    to { 
        opacity: 1;
        transform: translateY(0) scale(1);
    }
}

.modal-header {
    padding: 20px 24px;
    display: flex;
    align-items: center;
    justify-content: space-between;
    border-bottom: 1px solid var(--gray-200);
}

.modal-header h2 {
    font-size: 20px;
    margin: 0;
}

.modal-body {
    padding: 24px;
}

.close {
    font-size: 24px;
    color: var(--gray-500);
    cursor: pointer;
    transition: color 0.15s ease;
    display: flex;
    align-items: center;
    justify-content: center;
    width: 32px;
    height: 32px;
    border-radius: 50%;
}

.close:hover {
    color: var(--gray-800);
    background-color: var(--gray-100);
}

.input-group {
    margin-bottom: 20px;
}

.input-group:last-child {
    margin-bottom: 0;
}

.input-group label {
    display: block;
    margin-bottom: 8px;
    color: var(--gray-700);
    font-size: 14px;
    font-weight: 500;
}

.cancel-btn {
    background: var(--gray-200);
    color: var(--gray-700);
}

.cancel-btn:hover {
    background: var(--gray-300);
}

.save-btn {
    background: var(--primary);
}

/* Log Content */
.log-content {
    padding: 20px 24px;
    font-size: 13px;
    line-height: 1.6;
    max-height: 280px;
    overflow-y: auto;
    color: var(--gray-700);
    scrollbar-width: thin;
    scrollbar-color: var(--gray-300) transparent;
}

.log-content::-webkit-scrollbar {
    width: 6px;
}

.log-content::-webkit-scrollbar-track {
    background: transparent;
}

.log-content::-webkit-scrollbar-thumb {
    background-color: var(--gray-300);
    border-radius: 20px;
}

.log-content table {
    width: 100%;
    border-collapse: collapse;
    margin-top: 10px;
}

.log-content th, .log-content td {
    padding: 10px 12px;
    text-align: left;
    border-bottom: 1px solid var(--gray-200);
}

.log-content th {
    background-color: var(--gray-50);
    font-weight: 600;
    color: var(--gray-700);
    position: sticky;
    top: 0;
    z-index: 10;
}

.log-content tr:hover td {
    background-color: var(--gray-50);
}

.log-content .success { 
    color: var(--success);
    display: flex;
    align-items: center;
    gap: 6px;
}

.log-content .success:before {
    content: '';
    display: inline-block;
    width: 12px;
    height: 12px;
    background-image: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="%2310b981" stroke-width="2"><path stroke-linecap="round" stroke-linejoin="round" d="M5 13l4 4L19 7" /></svg>');
    background-repeat: no-repeat;
    background-position: center;
    background-size: contain;
}

.log-content .failure { 
    color: var(--danger);
    display: flex;
    align-items: center;
    gap: 6px;
}

.log-content .failure:before {
    content: '';
    display: inline-block;
    width: 12px;
    height: 12px;
    background-image: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="%23ef4444" stroke-width="2"><path stroke-linecap="round" stroke-linejoin="round" d="M6 18L18 6M6 6l12 12" /></svg>');
    background-repeat: no-repeat;
    background-position: center;
    background-size: contain;
}

/* Monitor Card Styles */
.monitor-card {
    border-left: 4px solid var(--primary);
    position: relative;
    overflow: hidden;
}

.monitor-content {
    padding: 24px;
    font-size: 14px;
    line-height: 1.7;
    position: relative;
}

.monitor-content:before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background-image: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" width="100" height="100" viewBox="0 0 100 100"><circle cx="50" cy="50" r="40" stroke="%23e5e7eb" stroke-width="1" fill="none" /></svg>'), 
                      url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" width="50" height="50" viewBox="0 0 50 50"><circle cx="25" cy="25" r="20" stroke="%23e5e7eb" stroke-width="0.5" fill="none" /></svg>');
    background-position: center center, 80% 20%;
    background-repeat: no-repeat;
    background-size: 120px, 80px;
    opacity: 0.4;
    z-index: 0;
}

.monitor-item {
    margin-bottom: 14px;
    display: flex;
    justify-content: space-between;
    align-items: center;
    position: relative;
    z-index: 1;
    padding: 8px 12px;
    border-radius: var(--radius-sm);
}

.monitor-item:hover {
    background-color: var(--gray-50);
}

.monitor-item:last-child {
    margin-bottom: 0;
}

.monitor-item span {
    color: var(--gray-800);
    text-align: right;
    font-family: 'SF Mono', 'Menlo', Monaco, 'Courier New', monospace;
    font-size: 13px;
}

.monitor-item strong {
    color: var(--gray-600);
    margin-right: 10px;
    font-weight: 500;
}

/* Animation */
@keyframes pulse {
    0% { opacity: 1; }
    50% { opacity: 0.6; }
    100% { opacity: 1; }
}

@keyframes spin {
    0% { transform: rotate(0deg); }
    100% { transform: rotate(360deg); }
}

/* Responsive adjustments */
@media (min-width: 768px) {
    body {
        font-size: 16px;
    }
    
    .header {
        padding: 20px 32px;
    }
    
    .header h1 {
        font-size: 24px;
    }
    
    .card {
        margin: 24px auto;
        max-width: 560px;
    }
    
    .form-group {
        padding: 20px 24px;
    }
    
    .monitor-content {
        grid-template-columns: 1fr 1fr;
    }
    
    .button-row {
        gap: 16px;
    }
    
    .modal-content {
        margin: 100px auto;
        max-width: 420px;
    }
}

.icon-button {
    position: absolute;
    right: 5px;
    top: 50%;
    transform: translateY(-50%);
    width: 38px;
    height: 38px;
    min-width: 38px;
    padding: 7px;
    border-radius: 50%;
    background: transparent;
    color: var(--gray-500);
    border: none;
    cursor: pointer;
    transition: background-color 0.15s ease, color 0.15s ease;
    display: flex;
    align-items: center;
    justify-content: center;
}

.icon-button:hover {
    background-color: var(--gray-100);
    color: var(--gray-700);
}

.icon-button svg {
    width: 20px;
    height: 20px;
}

button:disabled {
    background: var(--gray-400);
    cursor: not-allowed;
}

.button-row {
    display: flex;
    gap: 12px;
}

.button-row button {
    flex: 1;
}

/* Settings - iOS style */
.setting-row {
    padding: 16px 20px;
    display: flex;
    align-items: center;
    border-bottom: 1px solid var(--gray-200);
    transition: background-color 0.15s ease;
}

.setting-row:hover {
    background-color: var(--gray-50);
}

.setting-row:last-child {
    border-bottom: none;
}

.setting-icon {
    margin-right: 16px;
    display: flex;
    align-items: center;
    justify-content: center;
    height: 32px;
    width: 32px;
    border-radius: 8px;
    background-color: var(--gray-100);
}

.setting-icon svg {
    width: 18px;
    height: 18px;
    stroke: var(--primary);
}

.settings-link {
    color: var(--gray-800);
    text-decoration: none;
    font-size: 16px;
    font-weight: 500;
    transition: color 0.15s ease;
    display: flex;
    align-items: center;
    justify-content: space-between;
    width: 100%;
}

.settings-link:after {
    content: '';
    display: inline-block;
    width: 8px;
    height: 13px;
    background-image: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="%238E8E93" stroke-width="2"><path stroke-linecap="round" stroke-linejoin="round" d="M9 5l7 7-7 7" /></svg>');
    background-repeat: no-repeat;
    background-position: center;
    background-size: contain;
}

.settings-link:hover {
    color: var(--primary);
}

/* IP Display - iOS style */
#ip-display {
    position: fixed;
    bottom: 0;
    left: 0;
    width: 100%;
    display: flex;
    align-items: center;
    justify-content: space-between;
    padding: 12px 20px;
    background: rgba(255, 255, 255, 0.85);
    backdrop-filter: blur(10px);
    -webkit-backdrop-filter: blur(10px);
    border-top: 1px solid var(--gray-200);
    box-shadow: var(--shadow-md);
    z-index: 100;
}

/* Modal - iOS style */
.modal {
    display: none;
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: rgba(0, 0, 0, 0.5);
    backdrop-filter: blur(5px);
    -webkit-backdrop-filter: blur(5px);
    z-index: 200;
    animation: fadeIn 0.2s ease;
}

.modal-content {
    background: white;
    border-radius: 14px;
    margin: 60px auto;
    max-width: 360px;
    width: calc(100% - 40px);
    overflow: hidden;
    box-shadow: 0 10px 25px rgba(0, 0, 0, 0.12);
    animation: slideIn 0.25s cubic-bezier(0.25, 0.46, 0.45, 0.94);
    transform-origin: top center;
}

.modal-header {
    padding: 16px 20px;
    display: flex;
    align-items: center;
    justify-content: space-between;
    border-bottom: 1px solid var(--gray-200);
}

.modal-header h2 {
    font-size: 18px;
    margin: 0;
}

.modal-body {
    padding: 20px;
}

.close {
    font-size: 28px;
    font-weight: 400;
    color: var(--gray-500);
    cursor: pointer;
    transition: color 0.15s ease;
    display: flex;
    align-items: center;
    justify-content: center;
    width: 28px;
    height: 28px;
    line-height: 1;
}

.close:hover {
    color: var(--gray-800);
}

/* Monitor Card Styles - iOS style */
.monitor-card {
    border-left: 3px solid var(--primary);
    position: relative;
    overflow: hidden;
}

.monitor-content {
    padding: 20px;
    font-size: 15px;
    line-height: 1.4;
    position: relative;
    display: grid;
    grid-template-columns: 1fr;
    gap: 12px;
}

.monitor-item {
    display: flex;
    justify-content: space-between;
    align-items: center;
    position: relative;
    z-index: 1;
    padding: 10px 12px;
    border-radius: var(--radius-sm);
    background-color: var(--gray-50);
    transition: background-color 0.2s ease;
}

.monitor-item:hover {
    background-color: var(--gray-100);
}

.monitor-item span {
    color: var(--gray-800);
    text-align: right;
    font-family: 'SF Mono', Menlo, Monaco, Consolas, monospace;
    font-size: 14px;
}

.monitor-item strong {
    color: var(--gray-600);
    margin-right: 10px;
    font-weight: 500;
}

.secondary-button {
    background: rgba(0, 122, 255, 0.1);
    color: var(--primary);
}

.secondary-button:hover {
    background: rgba(0, 122, 255, 0.15);
}

.secondary-button:active {
    background: rgba(0, 122, 255, 0.2);
}

.cancel-btn {
    background: var(--gray-200);
    color: var(--gray-700);
}

.cancel-btn:hover {
    background: var(--gray-300);
}

.save-btn {
    background: var(--primary);
}

/* Animation */
@keyframes pulse {
    0% { opacity: 1; }
    50% { opacity: 0.6; }
    100% { opacity: 1; }
}

@keyframes spin {
    0% { transform: rotate(0deg); }
    100% { transform: rotate(360deg); }
}

/* Responsive adjustments */
@media (min-width: 768px) {
    body {
        font-size: 16px;
    }
    
    .header {
        padding: 20px 32px;
    }
    
    .header h1 {
        font-size: 24px;
    }
    
    .card {
        margin: 24px auto;
        max-width: 560px;
    }
    
    .form-group {
        padding: 20px 24px;
    }
    
    .monitor-content {
        grid-template-columns: 1fr 1fr;
    }
    
    .button-row {
        gap: 16px;
    }
    
    .modal-content {
        margin: 100px auto;
        max-width: 420px;
    }
}
)rawliteral";

// Main content template - iOS style
const char CONTENT_TEMPLATE[] PROGMEM = R"rawliteral(
<div class='form-group'>
    <label for='ssid'>Choose Network</label>
    <div class="select-wrapper">
        <select id='ssid' name='ssid' required>
            <option value=''>Select a network...</option>
        </select>
    </div>
</div>
<div class='form-group'>
    <label for='password'>Password</label>
    <div class="input-wrapper">
        <input type='password' id='password' name='password' placeholder='Enter network password' required>
        <button type="button" id="toggle-password" class="icon-button" aria-label="Toggle password visibility">
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor" class="eye-icon">
                <path stroke-linecap="round" stroke-linejoin="round" d="M2.036 12.322a1.012 1.012 0 010-.639C3.423 7.51 7.36 4.5 12 4.5c4.638 0 8.573 3.007 9.963 7.178.07.207.07.431 0 .639C20.577 16.49 16.64 19.5 12 19.5c-4.638 0-8.573-3.007-9.963-7.178z" />
                <path stroke-linecap="round" stroke-linejoin="round" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
            </svg>
        </button>
    </div>
</div>
<div class='form-group'>
    <div class='button-row'>
        <button type='button' id='scan-btn' onclick='scanNetworks()' class="secondary-button">
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" d="M16.023 9.348h4.992v-.001M2.985 19.644v-4.992m0 0h4.992m-4.993 0l3.181 3.183a8.25 8.25 0 0013.803-3.7M4.031 9.865a8.25 8.25 0 0113.803-3.7l3.181 3.182m0-4.991v4.99" />
            </svg>
            Scan
        </button>
        <button type='button' id='connect-btn' onclick='connectToWiFi()'>
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" d="M13.5 4.5L21 12m0 0l-7.5 7.5M21 12H3" />
            </svg>
            Connect
        </button>
    </div>
</div>
)rawliteral";

// JavaScript code - Remains the same
const char JS_SCRIPT[] PROGMEM = R"rawliteral(
// Helper function to convert RSSI to signal bars using Unicode escapes
function getSignalBars(rssi) {
    // Bars ordered from weakest to strongest: ▂▄▆█
    if (rssi >= -55) { return '\u2582\u2584\u2586\u2588'; } // Excellent
    if (rssi >= -65) { return '\u2582\u2584\u2586'; }      // Good
    if (rssi >= -75) { return '\u2582\u2584'; }           // Fair
    if (rssi >= -85) { return '\u2582'; }                // Poor
    return '';                             // Very Poor / No Signal
}

// Scan WiFi networks
function scanNetworks() {
    const scanBtn = document.getElementById('scan-btn');
    const select = document.getElementById('ssid');
    const status = document.getElementById('status-bar');
    
    // Update UI state
    scanBtn.disabled = true;
    scanBtn.innerHTML = '<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor" style="animation: spin 1s linear infinite;"><path stroke-linecap="round" stroke-linejoin="round" d="M16.023 9.348h4.992v-.001M2.985 19.644v-4.992m0 0h4.992m-4.993 0l3.181 3.183a8.25 8.25 0 0013.803-3.7M4.031 9.865a8.25 8.25 0 0113.803-3.7l3.181 3.182m0-4.991v4.99" /></svg>Scanning...';
    select.innerHTML = '<option value="">Scanning...</option>';
    status.textContent = 'Scanning for networks...';
    
    // Perform scan
    fetch('/scan')
        .then(response => {
            if (!response.ok) {
                throw new Error('Network scan failed');
            }
            return response.json();
        })
        .then(data => {
            select.innerHTML = '<option value="">Select a network...</option>';
            if (data.networks && Array.isArray(data.networks)) {
                if (data.networks.length === 0) {
                    status.textContent = 'No networks found';
                } else {
                    status.textContent = `Found ${data.networks.length} networks`;
                    
                    // Sort networks by signal strength
                    data.networks.sort((a, b) => b.rssi - a.rssi);
                    
                    data.networks.forEach(net => {
                        const signalBars = getSignalBars(net.rssi);
                        const lock = net.isEncrypted ? '🔒 ' : '';
                        select.innerHTML += `<option value='${net.ssid}'>${lock}${net.ssid} ${signalBars}</option>`;
                    });
                }
            }
        })
        .catch(error => {
            console.error('Error:', error);
            status.textContent = 'Error scanning networks';
            select.innerHTML = '<option value="">Error scanning networks</option>';
        })
        .finally(() => {
            scanBtn.disabled = false;
            scanBtn.innerHTML = '<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" d="M16.023 9.348h4.992v-.001M2.985 19.644v-4.992m0 0h4.992m-4.993 0l3.181 3.183a8.25 8.25 0 0013.803-3.7M4.031 9.865a8.25 8.25 0 0113.803-3.7l3.181 3.182m0-4.991v4.99" /></svg>Scan';
        });
}

// Handle WiFi connection
function connectToWiFi() {
    const ssid = document.getElementById('ssid').value;
    const password = document.getElementById('password').value;
    const status = document.getElementById('status-bar');
    const connectBtn = document.getElementById('connect-btn');
    
    if (!ssid) {
        status.textContent = 'Please select a network';
        return;
    }
    
    status.textContent = `Connecting to ${ssid}...`;
    connectBtn.disabled = true;
    connectBtn.innerHTML = '<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor" style="animation: spin 1s linear infinite;"><path stroke-linecap="round" stroke-linejoin="round" d="M16.023 9.348h4.992v-.001M2.985 19.644v-4.992m0 0h4.992m-4.993 0l3.181 3.183a8.25 8.25 0 0013.803-3.7M4.031 9.865a8.25 8.25 0 0113.803-3.7l3.181 3.182m0-4.991v4.99" /></svg>Connecting...';
    
    fetch('/connect', {
        method: 'POST',
        headers: {'Content-Type': 'application/json'},
        body: JSON.stringify({ssid, password})
    })
    .then(response => response.json())
    .then(data => {
        status.textContent = data.message;
    })
    .catch(error => {
        console.error('Error:', error);
        status.textContent = 'Connection failed';
    })
    .finally(() => {
        connectBtn.disabled = false;
        connectBtn.innerHTML = '<svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="2" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" d="M13.5 4.5L21 12m0 0l-7.5 7.5M21 12H3" /></svg>Connect';
    });
}

// Helper function to format seconds into HH:MM:SS
function formatUptime(totalSeconds) {
    if (isNaN(totalSeconds) || totalSeconds < 0) return '00:00:00';
    const hours = String(Math.floor(totalSeconds / 3600)).padStart(2, '0');
    const minutes = String(Math.floor((totalSeconds % 3600) / 60)).padStart(2, '0');
    const seconds = String(totalSeconds % 60).padStart(2, '0');
    return `${hours}:${minutes}:${seconds}`;
}

// Update connection status and IP address, now includes monitor card update
function updateStatus() {
    fetch('/status')
        .then(response => {
            if (!response.ok) {
                throw new Error('Status update failed');
            }
            return response.json();
        })
        .then(data => {
            const status = document.getElementById('status-bar');
            const ipDisplay = document.getElementById('ip-address');
            const monitorCard = document.getElementById('monitor-card');
            let statusText = '';
            
            // Update title and header with current device name if available
            if (data.deviceName) {
                document.title = data.deviceName;
                const headerTitle = document.querySelector('.header h1');
                if (headerTitle) {
                    headerTitle.textContent = data.deviceName;
                }
            }

            if (data.connected) {
                statusText = `Connected to ${data.ssid}`; // Show connected network name
                ipDisplay.textContent = data.ip;

                // Update Monitor Card
                document.getElementById('mon-ssid').textContent = data.ssid || '-';
                document.getElementById('mon-ip').textContent = data.ip || '-';
                document.getElementById('mon-rssi').textContent = data.rssi ? `${data.rssi} dBm` : '-';
                document.getElementById('mon-status').textContent = 'Connected ✅';
                document.getElementById('mon-uptime').textContent = formatUptime(data.uptime_s) || '00:00:00';
                monitorCard.style.display = 'block'; // Show monitor card

            } else if (data.mode === 'AP') {
                statusText = 'Access Point mode active';
                ipDisplay.textContent = data.ip;
                monitorCard.style.display = 'none'; // Hide monitor card
            } else {
                statusText = 'Disconnected';
                ipDisplay.textContent = 'Not connected';
                 // Update Monitor Card for disconnected state
                document.getElementById('mon-ssid').textContent = '-';
                document.getElementById('mon-ip').textContent = '-';
                document.getElementById('mon-rssi').textContent = '-';
                document.getElementById('mon-status').textContent = 'Disconnected ❌';
                document.getElementById('mon-uptime').textContent = '-';
                monitorCard.style.display = 'block'; // Show monitor card even when disconnected
            }

            status.textContent = statusText;
        })
        .catch(error => {
            console.error('Error updating status:', error);
            // Optionally hide or show error state in monitor card
             document.getElementById('monitor-card').style.display = 'none';
        });
}

// Update Connection History display
function updateHistory() {
    const historyDiv = document.getElementById('connection-history');
    historyDiv.innerHTML = 'Loading history...';
    fetch('/history')
        .then(response => {
            if (!response.ok) throw new Error('Failed to fetch history');
            return response.json();
        })
        .then(data => {
            if (data.events && Array.isArray(data.events) && data.events.length > 0) {
                let tableHtml = '<table><thead><tr><th>Time</th><th>SSID</th><th>Status</th><th>RSSI</th></tr></thead><tbody>';
                // Reverse to show latest first
                data.events.slice().reverse().forEach(event => { 
                    const statusClass = event.success ? 'success' : 'failure';
                    const statusText = event.success ? 'Success' : 'Failed';
                    const rssiText = event.success ? event.rssi + ' dBm' : '-';
                    tableHtml += `<tr><td>${event.timestamp}</td><td>${event.ssid}</td><td class="${statusClass}">${statusText}</td><td>${rssiText}</td></tr>`;
                });
                tableHtml += '</tbody></table>';
                historyDiv.innerHTML = tableHtml;
            } else {
                historyDiv.innerHTML = 'No connection history yet.';
            }
        })
        .catch(error => {
            console.error('Error updating history:', error);
            historyDiv.innerHTML = 'Error loading history.';
        });
}

// Update Network Statistics display
function updateStats() {
    const statsDiv = document.getElementById('network-stats');
    statsDiv.innerHTML = 'Loading stats...';
    fetch('/stats')
        .then(response => {
             if (!response.ok) throw new Error('Failed to fetch stats');
            return response.json();
        })
        .then(data => {
             if (data.statistics && Object.keys(data.statistics).length > 0) {
                let tableHtml = '<table><thead><tr><th>SSID</th><th>Success</th><th>Failed</th><th>Rate</th></tr></thead><tbody>';
                for (const ssid in data.statistics) {
                    const stats = data.statistics[ssid];
                    const success = stats.successful_connections || 0;
                    const failed = stats.failed_connections || 0;
                    const rate = stats.success_rate !== undefined ? stats.success_rate.toFixed(1) + '%' : 'N/A';
                    tableHtml += `<tr><td>${ssid}</td><td>${success}</td><td>${failed}</td><td>${rate}</td></tr>`;
                }
                tableHtml += '</tbody></table>';
                statsDiv.innerHTML = tableHtml;
             } else {
                 statsDiv.innerHTML = 'No network statistics yet.';
             }
        })
        .catch(error => {
            console.error('Error updating stats:', error);
            statsDiv.innerHTML = 'Error loading statistics.';
        });
}

// AP Settings modal functions
function showApSettings() {
    document.getElementById('ap-settings-modal').style.display = 'block';
    
    // Fetch current AP settings
    fetch('/get-ap-settings')
        .then(response => response.json())
        .then(data => {
            if (data.ssid) {
                document.getElementById('ap-ssid').value = data.ssid;
                if (data.password) {
                    // We don't want to show the actual password, just indicate it exists
                    document.getElementById('ap-password').placeholder = "Password exists (leave empty to keep)";
                } else {
                    document.getElementById('ap-password').placeholder = "Enter AP password";
                }
            }
        })
        .catch(error => {
            console.error('Error fetching AP settings:', error);
        });
}

function closeModal() {
    document.getElementById('ap-settings-modal').style.display = 'none';
}

function saveApSettings() {
    const ssid = document.getElementById('ap-ssid').value;
    const password = document.getElementById('ap-password').value;
    const status = document.getElementById('status-bar');
    
    if (!ssid) {
        alert('Please enter an AP name');
        return;
    }
    
    fetch('/ap-settings', {
        method: 'POST',
        headers: {'Content-Type': 'application/json'},
        body: JSON.stringify({ssid, password})
    })
    .then(response => response.json())
    .then(data => {
        status.textContent = 'Status: ' + data.message;
        closeModal();
    })
    .catch(error => {
        console.error('Error:', error);
        status.textContent = 'Status: Failed to save AP settings';
    });
}

// Add CSS animation
const style = document.createElement('style');
style.innerHTML = `
@keyframes spin {
    0% { transform: rotate(0deg); }
    100% { transform: rotate(360deg); }
}`;
document.head.appendChild(style);

// Initialize
window.onload = function() {
    setTimeout(scanNetworks, 500);
    updateStatus();
    updateHistory();
    updateStats();
    setInterval(updateStatus, 5000);
    
    // Setup password toggle functionality
    const togglePassword = document.getElementById('toggle-password');
    const passwordField = document.getElementById('password');
    
    if (togglePassword && passwordField) {
        togglePassword.addEventListener('click', function() {
            const type = passwordField.getAttribute('type') === 'password' ? 'text' : 'password';
            passwordField.setAttribute('type', type);
            
            // Update the icon
            const eyeIcon = this.querySelector('.eye-icon');
            if (type === 'text') {
                eyeIcon.innerHTML = `
                    <path stroke-linecap="round" stroke-linejoin="round" d="M3.98 8.223A10.477 10.477 0 001.934 12C3.226 16.338 7.244 19.5 12 19.5c.993 0 1.953-.138 2.863-.395M6.228 6.228A10.45 10.45 0 0112 4.5c4.756 0 8.773 3.162 10.065 7.498a10.523 10.523 0 01-4.293 5.774M6.228 6.228L3 3m3.228 3.228l3.65 3.65m7.894 7.894L21 21m-3.228-3.228l-3.65-3.65m0 0a3 3 0 10-4.243-4.243m4.242 4.242L9.88 9.88" />
                `;
            } else {
                eyeIcon.innerHTML = `
                    <path stroke-linecap="round" stroke-linejoin="round" d="M2.036 12.322a1.012 1.012 0 010-.639C3.423 7.51 7.36 4.5 12 4.5c4.638 0 8.573 3.007 9.963 7.178.07.207.07.431 0 .639C20.577 16.49 16.64 19.5 12 19.5c-4.638 0-8.573-3.007-9.963-7.178z" />
                    <path stroke-linecap="round" stroke-linejoin="round" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
                `;
            }
        });
    }
    
    // Close modal when clicking outside
    window.onclick = function(event) {
        const modal = document.getElementById('ap-settings-modal');
        if (event.target == modal) {
            closeModal();
        }
    }
};
)rawliteral";

#endif // WEB_INTERFACE_H 