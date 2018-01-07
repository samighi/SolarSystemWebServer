# SolarSystemWebServer

// SolarSystemWebServer
//
// Creates a web server for monitoring and control of a pico-solar installation. Designed
// to run on an esp8266 nodeMCU, and has been tested on board: "NodeMCU (1.0 ESP-12E Module".
//
// At setup the infrastructure is initialized: USB serial logging, WiFi network, Network Time Protocol client, 
// and SPIFFS file system.  Project-specific web services are then enabled including web pages for browser use.
