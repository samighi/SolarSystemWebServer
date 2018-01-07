
/*
    Tom Doyle, hereby disclaims all copyright interest in the
    program “SolarSystemWebServer” (which monitors and controls a
    pico-solar installation) written by Tom Doyle.

    signature of Tom Doyle 7 January 2018
    Tom Doyle, self

    Copyright 2018 Tom Doyle

    This file is part of SolarSystemWebServer.

    SolarSystemWebServer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SolarSystemWebServer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SolarSystemWebServer.  If not, see <http://www.gnu.org/licenses/>.
*/

// SolarSystemWebServer
//
// Creates a web server for monitoring and control of a pico-solar installation. Designed
// to run on an esp8266 nodeMCU, and has been tested on board: "NodeMCU (1.0 ESP-12E Module".
//
// At setup the infrastructure is initialized: USB serial loggin, WiFi network, Network Time Protocol client, 
// and SPIFFS file system.  Project-specific web services are then enabled including web pages for browser use.

// TODO: maybe store the browser web pages in the file system, with service calls to pick up
//       dynamic information.

// Assumes web pages are pre-loaded.  See instructions for "Uploading files to the file system" at:
//    https://github.com/esp8266/Arduino/blob/master/doc/filesystem.rst

// TODO: project name is wrong.  This might be helped when libraries are split off
// TODO: make sure all copied code is acknowledged



#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>

#include <TimeLib.h>

// TODO: Timezone library was busted for nodeMCU.  The project isn't active at the moment, but ought to get fixed somehow
//    I cloned the project: https://github.com/JChristensen/Timezone.git
//    Then copied it to the Arduino/libraries folder,
//    then changed #include <Time.h> to #incluide <TimeLib.h> in Timezone.cpp, based on info:
//     https://forum.arduino.cc/index.php?topic=96891.30
#include <Timezone.h>

#include <NTPClient.h>

#include <Streaming.h>


// web server, with port number
ESP8266WebServer server ( 80 );

void setup ( void ) {
  Serial.begin ( 115200 );
  Serial.println("");

  makeNetwork();

  ntpClientSetup();

  checkFileSystem();

  initServices();
}

void loop ( void ) {
  server.handleClient();

  periodicProcessing();

}

