
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

const char * checkFileSystem(void)
{
  // file system should be formatted and pre-loaded using the esp8266fs tool:
  //    https://github.com/esp8266/arduino-esp8266fs-plugin/blob/master/README.md
  // Note, this was my first tool, and I incorrectly copied the .jar file directly into <home_dir>/Arduion/tools
  //    The zip should be placed in <home_dir>/Arduino/tools before expansion, or be sure to create the
  //    two intermediate subfolders: ESP8266FS/tool
  //
  // When the tool runs, it overwrites the SPIFFS filesystem with an image of this sketch's "data" subfolder.
  // TODO: destructive write would be OK if an infrastructure for backing up all data were in place.  Make it so.

  static String htmlDump;
  htmlDump = "";

  SPIFFS.begin();


  FSInfo fsInfo;
  bool infoValid = SPIFFS.info(fsInfo);

  if (infoValid)
  {
    // file system exists, show info
    htmlDump += "<p>file system info:</p>\n";
    htmlDump += "<p>          capacity: " + String(fsInfo.totalBytes) + "</p>\n";
    htmlDump += "<p>              used: " + String(fsInfo.usedBytes) + "</p>\n";
    htmlDump += "<p>         available: " + String(fsInfo.totalBytes - fsInfo.usedBytes) + "</p>\n";
    htmlDump += "<p>        block size: " + String(fsInfo.blockSize) + "</p>\n";
    htmlDump += "<p>         page size: " + String(fsInfo.pageSize) + "</p>\n";
    htmlDump += "<p>    max open files: " + String(fsInfo.maxOpenFiles) + "</p>\n";
    htmlDump += "<p>   max path length: " + String(fsInfo.maxPathLength) + "</p>\n";

    Serial.println(htmlDump);
    Serial.println("");
  }


  Dir root = SPIFFS.openDir("/");

  htmlDump += "<p></p><p>checking contents of root directory</p>";
  Serial.println("checking contents of root directory");
  while (root.next())
  {
    Serial.print ("    File: ");
    Serial.print(root.fileName());
    Serial.print (", size: ");
    File thisFile = root.openFile("r");
    Serial.println(thisFile.size());
    htmlDump += "<p>    File: " + root.fileName() + ", size: " + String(thisFile.size()) + "</p>\n";
  }

  return htmlDump.c_str();
}

void showFiles(void)
{
  String fileReport("<html>\
  <head>\
    <meta http-equiv='refresh' content='2'/>\
    <title>Solar System Monitoring and Control</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Filesystem Report:</h1>\
    <p>Local Time is: " + fetchTime() + "</p>\
    <p>" + upTime() + "</p>\
" + checkFileSystem() + "\
  </body>\
</html>");

  sendHtml(fileReport);
}

