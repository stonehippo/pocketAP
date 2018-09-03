# Tools

## Script for generating SSL certs

This script originated at https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/examples/WiFiHTTPSServer/make-self-signed-cert.sh. Any copyright and license from that repo applies to this file.

Change the "your-name-here" to the organization you want to use instead. The srcipt will generate a new key.h and x509.h for you. Copy these into `src/ssl.h` (you'll need to make this file from the template `src/ssl.h.example`).

Note that you should use the 1024 bit key size, as most browsers and HTTP tools will reject a smaller key as broken these days. Also, if you want to avoid browser complaints, you can use a genuine CA-signed cert instead of the self-signed one we're generating here.