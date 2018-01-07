
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

void sendHtml(const String& html)
{
  server.send(html.length(), "text/html", html.c_str());
}

// TODO: DateTime string gets garbled sometimes, maybe 1 out of three.  It is not garbled in the log though.  At first I thought is was related to back to back requests, but it also happened after 20 seconds of inactivity.

String currentDataSet;
void parseArguments(String requestType)
{
  unsigned long argCount = server.args();
  String logString;
  String response;

  logString = "";
  logString += "request type: " + requestType;
  logString += ", arg count: " + String(argCount);
  Serial.println(logString);

  response += logString + "\n";

  for (int i = 0; i < argCount; i++)
  {
    String paramName = server.argName(i);
    String paramVal = server.arg(i);


    logString = "";
    logString += "    arg: " + paramName;
    logString += ", val: " + paramVal;
    Serial.println(logString);

    response += "<p>" + logString + "</p>\n";
  }

  String htmlResponse;
  htmlResponse += "<html>\
  <head>\
    <title>Service response</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Service response:</h1>\
    <p>DateTime: " + fetchTime() + "</p>\
    <p>" + upTime() + "</p>\
    " + response + "\
  </body>\
</html>";
  sendHtml(htmlResponse);
}

void handleGets(void)
{
  parseArguments("monitor");
}

void handleSets(void)
{
  parseArguments("control");
}

// TODO: actually graph something
void customGraph(void)
{
  parseArguments("graph");
}

