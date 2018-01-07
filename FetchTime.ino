
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

//US Eastern Time Zone (New York, Detroit)
TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240};  //Eastern Daylight Time = UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};   //Eastern Standard Time = UTC - 5 hours
Timezone usET(usEDT, usEST);

String & fetchTime(void)
{
  static String timeString;

  time_t utc = fetchEpoch();

  TimeChangeRule *tcr;
  time_t localTime = usET.toLocal(utc, &tcr);

  timeString = String(month(localTime)) + "/" + String(day(localTime)) + "/" + String(year(localTime)) + " " + String(hour(localTime)) + ":" + String(minute(localTime)) + ":" + String(second(localTime)) + " " + tcr->abbrev;

  Serial.println(timeString);

  return timeString;
}

String & upTime(void)
{
  char timeBuf[50];

  unsigned long upMillis = millis();
  unsigned long upSeconds = upMillis / 1000;
  unsigned long upMinutes = upSeconds / 60;
  unsigned long upHours = upMinutes / 60;
  unsigned long upDays = upHours / 24;

  upSeconds %= 60;
  upMinutes %= 60;
  upHours %= 24;

  snprintf(timeBuf, sizeof(timeBuf), "Up days: %d, Uptime: %02d:%02d:%02d", upDays, upHours, upMinutes, upSeconds);

  static String upString;
  upString = timeBuf;

  return upString;
}

