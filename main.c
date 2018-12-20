#include <stdio.h>
#include <string.h>

#include <curl/curl.h>
#include "config.h"

#include "public.c"
#include "private.c"

/* Simple program that fetches your IP(v4/v6) Address (local or public; public by default.). */

int main(int argc, char** argv) {
	if (argc > 1) {
		if (!strcmp(argv[1], "--help") || !(strcmp(argv[1], "-h"))) {
			printf("A relatively simple program to get the IPV4/IPV6 address that you're on. (public or private; public by default)\n");
			printf("Usage: ");
			printf("ip [options]\n");
			printf("-4, --ipv4	Get IPV4 instead of default\n");
			printf("-6, --ipv6	Get IPV6 instead of default\n");
			printf("-p, --private	Obtain the private IP instead of the public one (lan IP) (-a/--all; all adapters; no need for a specific one) (adapter) (will get ipv6 and ipv4; wont be changed.) \n");
			printf("-h, --help	Show this menu\n");
			printf("\n\n\nYou can also find cool things in the config.h file!\n");
			return 0;
		}

		if (!strcmp(argv[1], "-p") || !strcmp(argv[1], "--private")) {

			if (argv[2] == NULL && DEFAULT_ADAPTER == NULL) {
				printf("An adapter is needed, and you don't have a default one set. Use 'ip address' to see your adapters if you're unsure. Or, type -a/--all here to give all adapters--and their IP's.\n");
				return 1;
			}

			if (argv[2] == NULL && DEFAULT_ADAPTER != NULL) {
				print_private_ips(DEFAULT_ADAPTER, 0);
				return 0;
			}

			if (!strcmp(argv[2], "--all") || !(strcmp(argv[2], "-a"))) {
				print_private_ips((const char*) argv[2], 1);
				return 0;
			}

			print_private_ips((const char*) argv[2], 0);

			return 0;
		}

		if (!strcmp(argv[1], "--ipv6") || !strcmp(argv[1], "-6")) {
			print_ip(IPV6);
			return 0;
		}	

		if (!strcmp(argv[1], "--ipv4") || !(strcmp(argv[1], "-4"))) {
			print_ip(IPV4);
			return 0;
		}

	}
	/* Default operation (no args) */
	switch (preferred_ip_type) {
		case p_ipv4:
			print_ip(IPV4);
			break;
		case p_ipv6:
			print_ip(IPV6);
			break;
	}
	
	return 0;
}
