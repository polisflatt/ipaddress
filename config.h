#pragma once

#include <stddef.h>

#include "types.h"


/* The minimal configuration file for ipaddr */ 

/* Friendly section */
char* IP_LINK = "ipinfo.io"; /* IP/Domain to curl, to get your IP. */
char* DEFAULT_ADAPTER = "enp0s25"; /* Put to NULL if you want to disable this feature. */
p_ip_type preferred_ip_type = p_ipv4;
