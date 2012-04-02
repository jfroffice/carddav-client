Most common network problems and solutions

Error code 0 and possible causes of the error:

1.) Make sure you have correct CardDavMATE configuration (see the config.js)

2.) Use a supported browser (and always use the latest version):
    - any Webkit based browser (Safari, Webkit, Epiphany, iCab, Chrome)
    - any Gecko based browser (Firefox, Iceweasel, SeaMonkey)
    - ! IE is not supported (missing XDomainRequest support in jQuery)
    - ! Opera is not supported (missing cross domain query implementation)

3.) Make sure you have correct server configuration:
    - for Davical see the config_davical.txt in the misc directory and set the
      Access-Control-Allow-Origin to "*"
    - in the config.js set the withCredentials for your resource to false
    - for MacOS X Lion Server see the lion_readme.txt in the misc directory

4.) Try to use CardDavMATE with http resources (without SSL)

5.) Check the connection to your resource URL by visiting it using your browser
    - if your browser asks the username and password then your connection is OK
    - otherwise check your network configuration, proxy and firewall settings

6.) If your CardDavMATE installation works, then:
    - for Davical you can change the Access-Control-Allow-Origin to your origin
      url - protocol,server,port of the originating content (for example if your
      CardDavMATE URL is "http://server.com/carddavmate" then your origin url is
      "http://server.com")
    - for MacOS X Lion Server you can also modify the Access-Control-Allow-Origin
      in the calendarserver source code (not necessary nor recommended)
    - if your Access-Control-Allow-Origin is NOT "*" then you can change the
      withCredentials for your resource to true in config.js (not necessary nor
      recommended)

7.) Use SSL and make sure your certificate is:
    - trusted by certificate authority (CA)
    - if your certificate is issued by your CA, make sure your CA is trusted
      by your browser (browser settings -> trusted root certificates)
    - if you are using self signed certificate you must add security exception
      for your certificate (visit the resource url and add permanent exception)

