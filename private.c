#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "config.h"

void print_private_ips(const char* adapter_name, int all) {
    struct ifaddrs* ifaddr = NULL;
    struct ifaddrs* tempIfAddr = NULL;
    void *tempAddrPtr = NULL;
    int return_code = getifaddrs(&ifaddr);

    if (return_code != EXIT_SUCCESS) { /* Failed to get adapters */
        printf("Error getting adapters.\n");
        exit(EXIT_FAILURE);
    }

    char returned_address[512];

    for(tempIfAddr = ifaddr; tempIfAddr != NULL; tempIfAddr = tempIfAddr->ifa_next) {
        if (!all) { /* Are we not doing all adapters? */
            if (!!strcmp(tempIfAddr->ifa_name, adapter_name)) { /* Did the adapter match? If not, continue */
                continue;
            }
        }

        tempAddrPtr = &((struct sockaddr_in *)tempIfAddr->ifa_addr)->sin_addr;
        printf("Adapter: %s\n", tempIfAddr->ifa_name);
        printf("IP: %s\n\n", inet_ntop(tempIfAddr->ifa_addr->sa_family, tempAddrPtr, returned_address, sizeof(returned_address)));
          
    }

    /* freeifaddrs(ifaddr); */

}