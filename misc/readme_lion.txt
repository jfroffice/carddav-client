MacOSX Lion Server instructions:

1. Calendarserver in MacOS X Lion not sends headers required by web browsers to allow cross domain queries. To add these headers follow the steps below: 
	- copy the misc/calendarserver_CardDavMATE.diff to any directory on your server (for example: ~/Desktop)
	- if your server is already patched (previous version of CardDavMATE patch) you must restore the original files from backup:
		sudo mv /usr/share/caldavd/lib/python/twext/web2/http_headers.py.orig /usr/share/caldavd/lib/python/twext/web2/http_headers.py
		sudo mv /usr/share/caldavd/lib/python/twext/web2/server.py.orig /usr/share/caldavd/lib/python/twext/web2/server.py
	- execute the following commands in Terminal:
		sudo patch -b -d /usr/share/caldavd/lib/python/twext/web2 -i ~/Desktop/calendarserver_CardDavMATE.diff
		sudo serveradmin stop addressbook
		sudo serveradmin start addressbook

2. The Digest authentication used in MacOS X Lion server is not supported by jQuery. You MUST disable it and enable the Basic authentication instead. To disable the Digest authentication execute the following commands in Terminal:
	sudo serveradmin settings calendar:Authentication:Basic:Enabled = yes
	sudo serveradmin settings calendar:Authentication:Digest:Enabled = no
	sudo serveradmin stop addressbook
	sudo serveradmin start addressbook
	

	WARNING: with Basic authentication your username and password are sent over the network in plain text.
	!!! ALWAYS USE SSL with Basic authentication !!!


Example config.js href values for MacOS X Lion server:
	href: http://lionserver.com:8008/principals/users/USERNAME/	(INSECURE!)
	href: https://lionserver.com:8443/principals/users/USERNAME/
