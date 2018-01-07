
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

#include <WiFiParams.h>

// WiFi station parameters are defined in WiFiParams.h
// It is kept in a separate library to avoid accidental publication
//
// To create your own WiFiParams library:
//    Create a subfolder "WiFiParams" in your Arduino libraries folder
//    Create a file "WiFiParams.h" in the new folder
//    Add the code below to the file
//    Update <your ssid> and <your password> for your network
//
// You can now use this library in other projects

/*
  #ifndef _WIFIPARAMS_H
  #define _WIFIPARAMS_H

  //   WiFi station parameters
  const char *ssid = "<your ssid>";
  const char *password = "<your password>";

  #endif _WIFIPARAMS_H
*/


const char *getSSID(void)
{
  return ssid;
}

const char *getPassword(void)
{
  return password;
}


