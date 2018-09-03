/**
 * Create a soft AP that we can configure on the fly
 */

#include <Arduino.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServerSecure.h>

#include "main.h"
#include "ssl.h"

// Max size for AP SSID or password is 32 chars (EEPROM allocations 33 bytes for end of string char)
#define SSID_FIELD_START        0
#define SSID_FIELD_END          32
#define PASSWORD_FIELD_START    33
#define PASSWORD_FIELD_END      65

// Hardcode default AP settings
#define AP_DEFAULT_NAME         "pocketAP"
#define AP_DEFAULT_PASSWORD     "secure_this_ap"
#define AP_DEFAULT_MDNS         "pocketAP"

// Secure Web server for config
ESP8266WebServerSecure server(443);

/**
 * Helper function to clear out a specific field stored in the EEPROM.
 * By default, will clear the entire EEPROM
 */
void clearEEPROMField(int start = 0, int end = 512) {
    for (int i = start; i < end; i++) {
        EEPROM.write(i, 0);
    }
}

void writeField(const char *value, int start, int end) {
    
}

void readField(char *value, int start, int end) {
    
}

/**
 * store the AP name in EEPROM
 */
void setAPName(const char *ssid) {
    writeField(ssid, SSID_FIELD_START, SSID_FIELD_END);
}

/**
 * store the AP password in EEPROM
 */
void setAPPassword(const char *password) {
    writeField(password, PASSWORD_FIELD_START, PASSWORD_FIELD_END);
}

/**
 * Helper to set the full config in one shot
 */
void setAPProperties(const char *ssid, const char *password) {
    setAPName(ssid);
    setAPPassword(password);
}

void getAPProperties(char *ssid, char *password) {
    
}

/**
 * check to see if we have a valid config in the EEPROM
 */
boolean isAPConfigured() {
    return false;
}

/**
 * Start up the AP with the name and password stored in the EEPROM
 */
void startAP() {
    char *ssid;
    char *password;
    getAPProperties(ssid, password);
    WiFi.softAP(AP_DEFAULT_NAME, AP_DEFAULT_PASSWORD);
}

/**
 * Fire up mDNS advertising of the router
 */
void mDNSAdvertise() {
    MDNS.begin(AP_DEFAULT_MDNS);
}

/**
 * HTTP 200/OK for path "/" (root)
 */
void handleRoot() {
    String response = "<html><body><h1>Welcome to PocketAP</h1></body></html>";
    server.send(200, "text/html", response);
}

/**
 * HTTP 200/Ok for path "/setConfing"
 */
void handleSetConfig() {

}

/**
 * HTTP 404/Not Found handler
 */
void handleNotFound() {
    String response = "<html><body><h1>Invalid URL</h1></body></html>";
    server.send(404, "text/html", response);
}

/**
 * Set up the secure Web server for config
 */
void startServer() {
    server.setServerKeyAndCert_P(rsakey, sizeof(rsakey), x509, sizeof(x509));
    server.on("/", handleRoot);
    server.on("/setConfig", HTTP_POST, handleSetConfig);
    server.onNotFound(handleNotFound);
    server.begin();
}

/**
 * Ardunio lifecycle
 * 
 * Keep the setup and loop as simple as possible. Most of the work should get wrapped up
 * in the helpers above.
 */
void setup() {
    EEPROM.begin(512);
    Serial.begin(115200);
    // Use the hardcoded defaults if nothing is set in the EEPROM
    if(!isAPConfigured()) {
        setAPProperties(AP_DEFAULT_NAME, AP_DEFAULT_PASSWORD);
    }
    startAP();
    mDNSAdvertise();
    startServer();
}

void loop() {
    server.handleClient();
}
