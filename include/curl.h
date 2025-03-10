#pragma once

#include <stdint.h>

struct CURL;
struct CURLcode;

struct curl_slist {
    char* data;
    curl_slist* next;
};

#define curl_easy_init  ((CURL*(*)(void))0x039EF264)
#define curl_easy_setopt  ((int(*)(CURL*, int, ...))0x039EED18)
#define curl_easy_perform  ((int(*)(CURL*))0x039EF318)
#define curl_easy_cleanup  ((void(*)(CURL*))0x039EF258)
#define curl_slist_append  ((curl_slist*(*)(curl_slist*, const char*))0x03846700)
#define curl_slist_free_all  ((void(*)(curl_slist*))0x03846708)

/*
#define mc_curl_easy_init  ((CURL*(*)(void))0xc07ee170)
#define mc_curl_easy_setopt  ((int(*)(CURL*, int, ...))0xc07ee0f0)
#define mc_curl_easy_perform  ((int(*)(CURL*))0xc07ee0e0)
#define mc_curl_easy_cleanup  ((void(*)(CURL*))0xc07ee0c8)
#define mc_curl_slist_append  ((curl_slist*(*)(curl_slist*, const char*))0xc07ee160)
#define mc_curl_slist_free_all  ((void(*)(curl_slist*))0xc07ee168)*/

#define CURL_HTTP_VERSION_1_0 1
#define CURL_HTTP_VERSION_1_1 2
#define CURL_HTTP_VERSION_2_0 3
#define CURL_ERROR_SIZE 256

#define CURLOPTTYPE_LONG          00000
#define CURLOPTTYPE_OBJECTPOINT   10000
#define CURLOPTTYPE_FUNCTIONPOINT 20000
#define CURLOPTTYPE_OFF_T         30000

#define CURLOPT_WRITEDATA 10001
#define CURLOPT_URL 10002
#define CURLOPT_WRITEFUNCTION 20011
#define CURLOPT_VERBOSE              41
#define CURLOPT_HEADER               42
#define CURLOPT_NOPROGRESS           43
#define CURLOPT_NOSIGNAL             99
#define CURLOPT_WILDCARDMATCH       197
#define CURLOPT_FTPLISTONLY         48
#define CURLOPT_FTPAPPEND           50
#define CURLOPT_USE_SSL             119
#define CURLOPT_SSLCERTTYPE         100
#define CURLOPT_SSLKEYTYPE          101
#define CURLOPT_SSLENGINE           89
#define CURLOPT_SSLENGINE_DEFAULT   90
#define CURLOPT_DNS_USE_GLOBAL_CACHE 91
#define CURLOPT_DNS_CACHE_TIMEOUT  92
#define CURLOPT_PREQUOTE            93
#define CURLOPT_DEBUGFUNCTION       94
#define CURLOPT_DEBUGDATA           95
#define CURLOPT_COOKIESESSION       96
#define CURLOPT_CAPATH              97
#define CURLOPT_BUFFERSIZE          98
#define CURLOPT_NOSIGNAL           99
#define CURLOPT_DNS_USE_GLOBAL_CACHE 91
#define CURLOPT_DNS_CACHE_TIMEOUT  92
#define CURLOPT_HTTP_CONTENT_DECODING 158
#define CURLOPT_HTTP_TRANSFER_DECODING 157
#define CURLOPT_TIMEOUT_MS         155
#define CURLOPT_CONNECTTIMEOUT_MS  156
#define CURLOPT_EXPECT_100_TIMEOUT_MS  168
#define CURLOPT_NEW_DIRECTORY_PERMS 160
#define CURLOPT_NEW_FILE_PERMS      159
#define CURLOPT_MAXFILESIZE_LARGE   114
#define CURLOPT_TCP_KEEPALIVE       213
#define CURLOPT_TCP_KEEPIDLE        214
#define CURLOPT_TCP_KEEPINTVL       215
#define CURLOPT_PIPEWAIT            237
#define CURLOPT_CONNECTTIMEOUT      78
#define CURLOPT_TIMEOUT             13
#define CURLOPT_IPRESOLVE           113
#define CURLOPT_LOW_SPEED_LIMIT     19
#define CURLOPT_LOW_SPEED_TIME      20
#define CURLOPT_RESUME_FROM         21
#define CURLOPT_NETRC               51
#define CURLOPT_FOLLOWLOCATION      52
#define CURLOPT_TRANSFERTEXT        53
#define CURLOPT_PUT                 54
#define CURLOPT_POST                47
#define CURLOPT_POSTFIELDSIZE       60
#define CURLOPT_POSTFIELDS         10015
#define CURLOPT_COPYPOSTFIELDS      165
#define CURLOPT_HTTPPOST            10024
#define CURLOPT_HTTPHEADER          10023
#define CURLOPT_HTTP200ALIASES      10104
#define CURLOPT_HTTPHEADER          10023
#define CURLOPT_COOKIE              10022
#define CURLOPT_COOKIEFILE          10031
#define CURLOPT_COOKIEJAR           10082
#define CURLOPT_COOKIEFILE          10031
#define CURLOPT_COOKIEJAR           10082
#define CURLOPT_COOKIESESSION       96
#define CURLOPT_CUSTOMREQUEST       10036
#define CURLOPT_EGDSOCKET           10077
#define CURLOPT_ENCODING            10102
#define CURLOPT_PRIVATE             10103
#define CURLOPT_HTTP_VERSION        84
#define CURLOPT_USERAGENT           10018
#define CURLOPT_USERPWD             173
#define CURLOPT_PROXYUSERPWD        10006
#define CURLOPT_HTTPPROXYTUNNEL     61
#define CURLOPT_PROXY               10004
#define CURLOPT_PROXYPORT           59
#define CURLOPT_PROXYTYPE           101
#define CURLOPT_PROXYAUTH           111
#define CURLOPT_PROXYUSERPWD        10006
#define CURLOPT_PROXY_SERVICE_NAME  10235
#define CURLOPT_PROXY_TRANSFER_MODE  166
#define CURLOPT_PROXY_CAPATH        10309
#define CURLOPT_PROXY_CAINFO        10308
#define CURLOPT_PROXY_SSLCERT       10217
#define CURLOPT_PROXY_SSLCERTTYPE   10218
#define CURLOPT_PROXY_SSLKEY        10219
#define CURLOPT_PROXY_SSLKEYTYPE    10220
#define CURLOPT_PROXY_KEYPASSWD     10221
#define CURLOPT_PROXY_SSL_VERIFYPEER 10130
#define CURLOPT_PROXY_SSL_VERIFYHOST 10131
#define CURLOPT_PROXY_TLSAUTH_USERNAME 10223
#define CURLOPT_PROXY_TLSAUTH_PASSWORD 10224
#define CURLOPT_PROXY_TLSAUTH_TYPE  10225
#define CURLOPT_PROXY_TLSAUTH_SRP   10226
#define CURLOPT_PROXY_TLSAUTH_SRP_USERNAME 10227
#define CURLOPT_PROXY_TLSAUTH_SRP_PASSWORD 10228
#define CURLOPT_PROXY_SERVICE_NAME  10235
#define CURLOPT_PROXY_SSLVERSION    250
#define CURLOPT_PROXY_SSL_OPTIONS   261
#define CURLOPT_PROXY_SOCKS5_GSSAPI_SERVICE 10132
#define CURLOPT_PROXY_SSLCERT       10217
#define CURLOPT_PROXY_SSLCERTTYPE   10218
#define CURLOPT_PROXY_SSLKEY        10219
#define CURLOPT_PROXY_SSLKEYTYPE    10220
#define CURLOPT_PROXY_KEYPASSWD     10221
#define CURLOPT_PROXY_SSL_VERIFYPEER 10130
#define CURLOPT_PROXY_SSL_VERIFYHOST 10131
#define CURLOPT_PROXY_TLSAUTH_USERNAME 10223
#define CURLOPT_PROXY_TLSAUTH_PASSWORD 10224
#define CURLOPT_PROXY_TLSAUTH_TYPE  10225
#define CURLOPT_PROXY_TLSAUTH_SRP   10226
#define CURLOPT_PROXY_TLSAUTH_SRP_USERNAME 10227
#define CURLOPT_PROXY_TLSAUTH_SRP_PASSWORD 10228
#define CURLOPT_PROXY_TLSAUTH_TYPE  10225
#define CURLOPT_PROXY_TLSAUTH_SRP   10226
#define CURLOPT_PROXY_TLSAUTH_SRP_USERNAME 10227
#define CURLOPT_PROXY_TLSAUTH_SRP_PASSWORD 10228
#define CURLOPT_PROXY_SSLVERSION    250
#define CURLOPT_PROXY_SSL_OPTIONS   261
#define CURLOPT_PROXY_PINNEDPUBLICKEY 10230
#define CURLOPT_INTERFACE           10062
#define CURLOPT_KRB4LEVEL           10063
#define CURLOPT_CAINFO              10065
#define CURLOPT_CAINFO              10065
#define CURLOPT_ISSUERCERT          10170
#define CURLOPT_KEYPASSWD           10026
#define CURLOPT_SSLENGINE_DEFAULT   90
#define CURLOPT_SSLCERT            10025
#define CURLOPT_SSLCERTTYPE         10086
#define CURLOPT_SSLKEY             10087
#define CURLOPT_SSLKEYTYPE          10088
#define CURLOPT_KEYPASSWD           10026
#define CURLOPT_SSLENGINE           90
#define CURLOPT_SSLENGINE_DEFAULT   90
#define CURLOPT_NOBODY             44L
//#define CURLINFO_RESPONSE_CODE  0x200002
//#define CURLOPT_LOCALPORT 139
//#define CURLOPT_PROTOCOLS 181
