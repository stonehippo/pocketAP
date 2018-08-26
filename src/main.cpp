/**
 * Create a soft AP that we can configure on the fly
 */

#include <Arduino.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>

#include "main.h"

// Max size for AP SSID name or password is 32 chars (EEPROM allocations 33 bytes for end of string char)
#define NAME_FIELD_START        0
#define NAME_FIELD_END          32
#define PASSWORD_FIELD_START    33
#define PASSWORD_FIELD_END      65

// Hardcode default AP settings
#define AP_DEFAULT_NAME         "pocketAP"
#define AP_DEFAULT_PASSWORD     "secure_this_ap"

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
void setAPName(const char *name) {
    writeField(name, NAME_FIELD_START, NAME_FIELD_END);
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
void setAPProperties(const char *name, const char *password) {
    setAPName(name);
    setAPPassword(password);
}

void getAPProperties(char *name, char *password) {
    
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
    char *name;
    char *password;
    getAPProperties(name, password);
    WiFi.softAP(AP_DEFAULT_NAME, AP_DEFAULT_PASSWORD);
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
}

void loop() {
    
}
