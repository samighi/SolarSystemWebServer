
Here are a few screen shots:

RootPage.png:
Shows two graphs of random numbers.  Note timestamp is accurate, using NTP client.

FilesReport.png:
Dump of SPIFFS files system info, then lists the files present.  There a single file (index.html) that was pre-loaded from
this project's data folder, but it is currently unused.

MonitorQuery.png:
Result of monitor query (see the URL in the address bar).  For now, it's just a dump of the query parameters. Parameters use standard query format:
    <query type>?<param name>=<param value>&<param name>=<param value>&<param name>=<param value> ...
    where 
    <query type> is one of: "monitor", "control", or "graph".
    <param name> is a text string designating a specific parameter.  Supported names will be defined and hooked up to functions/
    <param value> is currently a text string, but will vary in accordance with the parameter name
