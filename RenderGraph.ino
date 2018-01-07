
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

// TODO: change this to call customGraph with default params

void renderRootGraph(void) {
  String out = "";
  char temp[100];
  int y;

  out += "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"440\" height=\"400\">\n";
  out += "<rect x=\"3\" y=\"200\" rx=\"10\" ry=\"10\" width=\"400\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"3\" stroke=\"rgb(0, 0, 0)\" />\n";

  out += "<g stroke=\"black\">\n";
  y = rand() % 130;
  for (int x = 10; x < 390; x += 10) {
    int y2 = rand() % 130;
    sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"2\" />\n", x, 340 - y, x + 10, 340 - y2);
    out += temp;
    y = y2;
  }
  out += "</g>\n";


  out += "<g stroke=\"black\" >\n";

  out += "<rect x=\"3\" y=\"10\" rx=\"10\" ry=\"10\" width=\"400\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"3\"/>\n";

  y = rand() % 130;
  for (int x = 10; x < 390; x += 10) {
    int y2 = rand() % 130;
    sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"2\" />\n", x, 150 - y, x + 10, 150 - y2);
    out += temp;
    y = y2;
  }
  out += "</g>\n";

  out += "</svg>\n";


  server.send ( 200, "image/svg+xml", out);
}

