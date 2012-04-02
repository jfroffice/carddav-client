The easiest way to use CardDavMATE is to copy it into Davical subdirectory and accessing this
  subdirectory by a browser (this is "normal setup" and it not requires any additional configuration).


Complete instructions:

First always try your setup without SSL!

Test setup:
- copy the source code into your server directory and update the globalAccountSettings in config.js
    note: set the crossDomain value in globalAccountSettings to true if your CardDavMATE origin
        (protocol,domain,port) is not exactly the same as your Davical origin, otherwise set to false
        for example:
            Davical installation: http://my.server.com:8080/
            CardDavMATE installation: http://my.server.com/ (the default port for http is 80)
            =>    crossDomain=true (the port is not the same)

            Davical installation: http://my.server.com/ (the default port for http is 80)
            CardDavMATE installation: http://my.server.com/carddavmate/ (the default port for http is 80)
            =>    crossDomain=false (the protocol,domain and also the port is the same)

            Davical installation: http://server.com/ (the default port for http is 80)
            CardDavMATE installation: http://www.server.com/carddavmate/ (the default port for http is 80)
            =>    crossDomain=true (the domain is not the same)

            Davical installation: https://server.com:8443/
            CardDavMATE installation: http://server.com/carddavmate/ (the default port for http is 80)
            =>    crossDomain=true (the protocol and the port is not the same)
- if your crossDomain is set to true you need to update your Apache configuration (on the server where your
    Davical is installed) and reload the Apache (see misc/config_davical.txt)
- done :)

Normal setup:
- copy the source code into your server directory
- if your CardDavMATE origin (protocol,domain,port) is exactly the same as your Davical origin you are done
- otherwise update the globalNetworkCheckSettings in config.js:
    set the crossDomain to true
    set the href value (URL to your server - not resource!), for example: http://davical.server.com:8080/caldav.php/
    update your Apache configuration (on the server where your Davical is installed) and reload the Apache (see misc/config_davical.txt)

Special setup (requires PHP >= 5.3):
- copy the source code into your server directory, disable the globalAccountSettings and update the
    globalNetworkAccountSettings in config.js:
      the href value must be set to your CardDavMATE installation auth directory
      the crossDomain value is usually false (your auth directory is on the same server as the CardDavMATE)
- update your auth/config.inc:
    set the $config['auth_method'] to 'generic' (this is the default)
    set the $config['accounts'] - usually you need to change only the "http://www.server.com:80" part of the
      href value but you can also change the syncinterval and timeout values
    set the $config['auth_send_authenticate_header'] to true
- update your auth/plugins/generic_conf.inc:
    set the $pluginconfig['base_url'] to your Davical installation URL
- visit the auth directory manually by browser and enter your Davical username and password - you will get
    a configuration XML for your installation (if not, check your previous settings again)
- update your auth/config.inc:
    set the $config['auth_send_authenticate_header'] back to false
- done :)

Secure setup:
- use SSL (https instead of http)

If something not works check the console log in your browser.
