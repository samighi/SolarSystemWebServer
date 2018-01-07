
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

void initServices(void)
{
  // root web page is for web browsers users to see
  server.on ( "/", rootPage );
  server.on ( "/rootGraph.svg", renderRootGraph );   // image for root page to show

  server.onNotFound ( unsupportedRequest );

  // show files
  server.on ("/files", showFiles);

  // query service
  server.on ("/monitor", handleGets);
  // control service
  server.on ("/control", handleSets);
  // graph generator
  server.on("/graph", customGraph);

  server.on("/showTest", showTest);
  server.on("/testfile.txt", testFile);

  server.begin();
  Serial.println ( "HTTP server started" );
}
