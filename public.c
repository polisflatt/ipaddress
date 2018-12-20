#include <stdio.h>
#include <string.h>

#include <curl/curl.h>
#include "config.h"


void print_ip(enum IP ip_type) {
    CURL* curl = curl_easy_init(); /* Initalize cURL */

    if (ip_type == IPV4) { /* Are we using IPV4 or IPV6? */
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    } else if (ip_type == IPV6) {
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V6);
    }

    curl_easy_setopt(curl, CURLOPT_URL, IP_LINK); /* URL */
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout); /* write to FILE* fp = fopen("/dev/stdout", "w"); */
	int result = curl_easy_perform(curl); /* Curl it!--and do someother things */

	curl_easy_cleanup(curl);

    /* Some error handling */

    if (result == CURLE_COULDNT_RESOLVE_HOST) {
        printf("Could not resolve host. Are you online?\n");
    }

    if (result == CURLE_URL_MALFORMAT) {
        printf("cURL said the URL is incorrect. Look in config.h?\n");
    }

    if (result == CURLE_COULDNT_RESOLVE_PROXY) {
        printf("The proxy cannot be resolved. Try fixing it.\n");
    }

    if (result == CURLE_HTTP_RETURNED_ERROR) {
        printf("HTTP Returned an error >= 400. Check your IP site?\n");
    }

    if (result == CURLE_WRITE_ERROR) {
        printf("Error writing curl to stdout!\n");
    }

    if (result == CURLE_OUT_OF_MEMORY) {
        printf("Insufficient memory.\n");
    }
    
    if (result == CURLE_SSL_CONNECT_ERROR) {
        printf("SSL Error.\n");
    }

    if (result == CURLE_FUNCTION_NOT_FOUND) {
        printf("Curl function not found!\n");
    }

    if (result == CURLE_TOO_MANY_REDIRECTS) {
        printf("Too many redirects! libcURL hit the maximum amount!\n");
    }

    if (result == CURLE_GOT_NOTHING) {
        printf("cURL got NULL.\n");
    }

}