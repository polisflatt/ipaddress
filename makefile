ipaddress: main.c
	gcc main.c -o ipaddress -lcurl
install: ipaddr
	install -d /usr/bin/
	install -m 777 ipaddress /usr/bin/
