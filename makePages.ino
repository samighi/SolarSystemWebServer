
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

void showTest(void)
{
  String rootHtml("<html>\
  <head>\
    <meta http-equiv='refresh' content='2'/>\
    <title>Solar System Monitoring and Control</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>System Report:</h1>\
    <p>Local Time is: " + fetchTime() + "</p>\
    <p>" + upTime() + "</p>\
    <iframe src='/testfile.txt' scrolling='no' frameborder='0'></iframe>\
  </body>\
</html>");

  sendHtml(rootHtml);
}

void testFile() {
  String text("<style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
    <p>this is a test</p><p>this is a test</p><p>this is a test</p>");
  sendHtml(text);
}


