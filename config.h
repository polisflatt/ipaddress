#pragma once

#include <stddef.h>

#include "types.h"


/* The minimal configuration file for ipaddr */ 

/* Friendly section */
char* IP_LINK = ""; /* IP/Domain to curl, to get your IP. I use: icanhazmyip.com*/
char* DEFAULT_ADAPTER = ""; /* Put to NULL if you want to disable this feature. */
p_ip_type preferred_ip_type = p_ipv4; (p_ipv4, p_ipv6; whatever you want to use; default is ipv4)
