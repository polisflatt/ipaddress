#pragma once

#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "config.h"

void print_private_ips(const char* adapter_name, enum IP ip_type);