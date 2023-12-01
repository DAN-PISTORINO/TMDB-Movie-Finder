/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * SPDX-License-Identifier: curl
 *
 ***************************************************************************/
/* lib/curl_config.h.in.  Generated somehow by cmake.  */

/* Location of default ca bundle */
/* #undef CURL_CA_BUNDLE */

/* define "1" to use built-in ca store of TLS backend */
/* #undef CURL_CA_FALLBACK */

/* Location of default ca path */
/* #undef CURL_CA_PATH */

/* Default SSL backend */
/* #undef CURL_DEFAULT_SSL_BACKEND */

/* disables alt-svc */
/* #undef CURL_DISABLE_ALTSVC */

/* disables cookies support */
/* #undef CURL_DISABLE_COOKIES */

/* disables Basic authentication */
/* #undef CURL_DISABLE_BASIC_AUTH */

/* disables Bearer authentication */
/* #undef CURL_DISABLE_BEARER_AUTH */

/* disables Digest authentication */
/* #undef CURL_DISABLE_DIGEST_AUTH */

/* disables Kerberos authentication */
/* #undef CURL_DISABLE_KERBEROS_AUTH */

/* disables negotiate authentication */
/* #undef CURL_DISABLE_NEGOTIATE_AUTH */

/* disables AWS-SIG4 */
/* #undef CURL_DISABLE_AWS */

/* disables DICT */
/* #undef CURL_DISABLE_DICT */

/* disables DNS-over-HTTPS */
/* #undef CURL_DISABLE_DOH */

/* disables FILE */
/* #undef CURL_DISABLE_FILE */

/* disables form api */
/* #undef CURL_DISABLE_FORM_API */

/* disables FTP */
/* #undef CURL_DISABLE_FTP */

/* disables GOPHER */
/* #undef CURL_DISABLE_GOPHER */

/* disables HSTS support */
/* #undef CURL_DISABLE_HSTS */

/* disables HTTP */
/* #undef CURL_DISABLE_HTTP */

/* disables IMAP */
/* #undef CURL_DISABLE_IMAP */

/* disables LDAP */
/* #undef CURL_DISABLE_LDAP */

/* disables LDAPS */
/* #undef CURL_DISABLE_LDAPS */

/* disables --libcurl option from the curl tool */
/* #undef CURL_DISABLE_LIBCURL_OPTION */

/* disables MIME support */
/* #undef CURL_DISABLE_MIME */

/* disables MQTT */
/* #undef CURL_DISABLE_MQTT */

/* disables netrc parser */
/* #undef CURL_DISABLE_NETRC */

/* disables NTLM support */
/* #undef CURL_DISABLE_NTLM */

/* disables date parsing */
/* #undef CURL_DISABLE_PARSEDATE */

/* disables POP3 */
/* #undef CURL_DISABLE_POP3 */

/* disables built-in progress meter */
/* #undef CURL_DISABLE_PROGRESS_METER */

/* disables proxies */
/* #undef CURL_DISABLE_PROXY */

/* disables RTSP */
/* #undef CURL_DISABLE_RTSP */

/* disables SMB */
/* #undef CURL_DISABLE_SMB */

/* disables SMTP */
/* #undef CURL_DISABLE_SMTP */

/* disables use of socketpair for curl_multi_poll */
/* #undef CURL_DISABLE_SOCKETPAIR */

/* disables TELNET */
/* #undef CURL_DISABLE_TELNET */

/* disables TFTP */
/* #undef CURL_DISABLE_TFTP */

/* disables verbose strings */
/* #undef CURL_DISABLE_VERBOSE_STRINGS */

/* to make a symbol visible */
/* #undef CURL_EXTERN_SYMBOL */
/* Ensure using CURL_EXTERN_SYMBOL is possible */
#ifndef CURL_EXTERN_SYMBOL
#define CURL_EXTERN_SYMBOL
#endif

/* Allow SMB to work on Windows */
#define USE_WIN32_CRYPTO 1

/* Use Windows LDAP implementation */
#define USE_WIN32_LDAP 1

/* Define if you want to enable IPv6 support */
#define ENABLE_IPV6 1

/* Define to 1 if you have the alarm function. */
/* #undef HAVE_ALARM */

/* Define to 1 if you have the arc4random function. */
/* #undef HAVE_ARC4RANDOM */

/* Define to 1 if you have the <arpa/inet.h> header file. */
/* #undef HAVE_ARPA_INET_H */

/* Define to 1 if you have _Atomic support. */
/* #undef HAVE_ATOMIC */

/* Define to 1 if you have the `fchmod' function. */
/* #undef HAVE_FCHMOD */

/* Define to 1 if you have the `fnmatch' function. */
/* #undef HAVE_FNMATCH */

/* Define to 1 if you have the `basename' function. */
/* #undef HAVE_BASENAME */

/* Define to 1 if bool is an available type. */
/* #undef HAVE_BOOL_T */

/* Define to 1 if you have the __builtin_available function. */
/* #undef HAVE_BUILTIN_AVAILABLE */

/* Define to 1 if you have the clock_gettime function and monotonic timer. */
/* #undef HAVE_CLOCK_GETTIME_MONOTONIC */

/* Define to 1 if you have the clock_gettime function and raw monotonic timer.
   */
/* #undef HAVE_CLOCK_GETTIME_MONOTONIC_RAW */

/* Define to 1 if you have the `closesocket' function. */
#define HAVE_CLOSESOCKET 1

/* Define to 1 if you have the fcntl function. */
/* #undef HAVE_FCNTL */

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have a working fcntl O_NONBLOCK function. */
/* #undef HAVE_FCNTL_O_NONBLOCK */

/* Define to 1 if you have the freeaddrinfo function. */
/* #undef HAVE_FREEADDRINFO */

/* Define to 1 if you have the fseeko function. */
/* #undef HAVE_FSEEKO */

/* Define to 1 if you have the _fseeki64 function. */
#define HAVE__FSEEKI64 1

/* Define to 1 if you have the ftruncate function. */
/* #undef HAVE_FTRUNCATE */

/* Define to 1 if you have a working getaddrinfo function. */
/* #undef HAVE_GETADDRINFO */

/* Define to 1 if the getaddrinfo function is threadsafe. */
/* #undef HAVE_GETADDRINFO_THREADSAFE */

/* Define to 1 if you have the `geteuid' function. */
/* #undef HAVE_GETEUID */

/* Define to 1 if you have the `getppid' function. */
/* #undef HAVE_GETPPID */

/* Define to 1 if you have the gethostbyname_r function. */
/* #undef HAVE_GETHOSTBYNAME_R */

/* gethostbyname_r() takes 3 args */
/* #undef HAVE_GETHOSTBYNAME_R_3 */

/* gethostbyname_r() takes 5 args */
/* #undef HAVE_GETHOSTBYNAME_R_5 */

/* gethostbyname_r() takes 6 args */
/* #undef HAVE_GETHOSTBYNAME_R_6 */

/* Define to 1 if you have the gethostname function. */
#define HAVE_GETHOSTNAME 1

/* Define to 1 if you have a working getifaddrs function. */
/* #undef HAVE_GETIFADDRS */

/* Define to 1 if you have the `getpass_r' function. */
/* #undef HAVE_GETPASS_R */

/* Define to 1 if you have the `getpeername' function. */
/* #undef HAVE_GETPEERNAME */

/* Define to 1 if you have the `getsockname' function. */
/* #undef HAVE_GETSOCKNAME */

/* Define to 1 if you have the `if_nametoindex' function. */
/* #undef HAVE_IF_NAMETOINDEX */

/* Define to 1 if you have the `getpwuid' function. */
/* #undef HAVE_GETPWUID */

/* Define to 1 if you have the `getpwuid_r' function. */
/* #undef HAVE_GETPWUID_R */

/* Define to 1 if you have the `getrlimit' function. */
/* #undef HAVE_GETRLIMIT */

/* Define to 1 if you have the `gettimeofday' function. */
/* #undef HAVE_GETTIMEOFDAY */

/* Define to 1 if you have a working glibc-style strerror_r function. */
/* #undef HAVE_GLIBC_STRERROR_R */

/* Define to 1 if you have a working gmtime_r function. */
/* #undef HAVE_GMTIME_R */

/* if you have the gssapi libraries */
/* #undef HAVE_GSSAPI */

/* Define to 1 if you have the <gssapi/gssapi_generic.h> header file. */
/* #undef HAVE_GSSAPI_GSSAPI_GENERIC_H */

/* Define to 1 if you have the <gssapi/gssapi.h> header file. */
/* #undef HAVE_GSSAPI_GSSAPI_H */

/* Define to 1 if you have the <gssapi/gssapi_krb5.h> header file. */
/* #undef HAVE_GSSAPI_GSSAPI_KRB5_H */

/* if you have the GNU gssapi libraries */
/* #undef HAVE_GSSGNU */

/* if you have the Heimdal gssapi libraries */
/* #undef HAVE_GSSHEIMDAL */

/* if you have the MIT gssapi libraries */
/* #undef HAVE_GSSMIT */

/* Define to 1 if you have the `idna_strerror' function. */
/* #undef HAVE_IDNA_STRERROR */

/* Define to 1 if you have the <ifaddrs.h> header file. */
/* #undef HAVE_IFADDRS_H */

/* Define to 1 if you have a IPv6 capable working inet_ntop function. */
/* #undef HAVE_INET_NTOP */

/* Define to 1 if you have a IPv6 capable working inet_pton function. */
/* #undef HAVE_INET_PTON */

/* Define to 1 if symbol `sa_family_t' exists */
/* #undef HAVE_SA_FAMILY_T */

/* Define to 1 if symbol `ADDRESS_FAMILY' exists */
/* #undef HAVE_ADDRESS_FAMILY */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the ioctlsocket function. */
#define HAVE_IOCTLSOCKET 1

/* Define to 1 if you have the IoctlSocket camel case function. */
/* #undef HAVE_IOCTLSOCKET_CAMEL */

/* Define to 1 if you have a working IoctlSocket camel case FIONBIO function.
   */
/* #undef HAVE_IOCTLSOCKET_CAMEL_FIONBIO */

/* Define to 1 if you have a working ioctlsocket FIONBIO function. */
#define HAVE_IOCTLSOCKET_FIONBIO 1

/* Define to 1 if you have a working ioctl FIONBIO function. */
/* #undef HAVE_IOCTL_FIONBIO */

/* Define to 1 if you have a working ioctl SIOCGIFADDR function. */
/* #undef HAVE_IOCTL_SIOCGIFADDR */

/* Define to 1 if you have the <io.h> header file. */
#define HAVE_IO_H 1

/* Define to 1 if you have the lber.h header file. */
/* #undef HAVE_LBER_H */

/* Define to 1 if you have the ldap.h header file. */
/* #undef HAVE_LDAP_H */

/* Use LDAPS implementation */
#define HAVE_LDAP_SSL 1

/* Define to 1 if you have the ldap_ssl.h header file. */
/* #undef HAVE_LDAP_SSL_H */

/* Define to 1 if you have the `ldap_url_parse' function. */
/* #undef HAVE_LDAP_URL_PARSE */

/* Define to 1 if you have the <libgen.h> header file. */
/* #undef HAVE_LIBGEN_H */

/* Define to 1 if you have the `idn2' library (-lidn2). */
/* #undef HAVE_LIBIDN2 */

/* Define to 1 if you have the idn2.h header file. */
/* #undef HAVE_IDN2_H */

/* Define to 1 if you have the `socket' library (-lsocket). */
/* #undef HAVE_LIBSOCKET */

/* Define to 1 if you have the `ssh2' library (-lssh2). */
/* #undef HAVE_LIBSSH2 */

/* if zlib is available */
#define HAVE_LIBZ 1

/* if brotli is available */
/* #undef HAVE_BROTLI */

/* if zstd is available */
/* #undef HAVE_ZSTD */

/* Define to 1 if you have the <locale.h> header file. */
/* #undef HAVE_LOCALE_H */

/* Define to 1 if the compiler supports the 'long long' data type. */
#define HAVE_LONGLONG 1

/* Define to 1 if you have the 'suseconds_t' data type. */
/* #undef HAVE_SUSECONDS_T */

/* Define to 1 if you have the MSG_NOSIGNAL flag. */
/* #undef HAVE_MSG_NOSIGNAL */

/* Define to 1 if you have the <netdb.h> header file. */
/* #undef HAVE_NETDB_H */

/* Define to 1 if you have the <netinet/in.h> header file. */
/* #undef HAVE_NETINET_IN_H */

/* Define to 1 if you have the <netinet/tcp.h> header file. */
/* #undef HAVE_NETINET_TCP_H */

/* Define to 1 if you have the <netinet/udp.h> header file. */
/* #undef HAVE_NETINET_UDP_H */

/* Define to 1 if you have the <linux/tcp.h> header file. */
/* #undef HAVE_LINUX_TCP_H */

/* Define to 1 if you have the <net/if.h> header file. */
/* #undef HAVE_NET_IF_H */

/* if you have an old MIT gssapi library, lacking GSS_C_NT_HOSTBASED_SERVICE */
/* #undef HAVE_OLD_GSSMIT */

/* Define to 1 if you have the `pipe' function. */
/* #undef HAVE_PIPE */

/* If you have a fine poll */
/* #undef HAVE_POLL_FINE */

/* Define to 1 if you have the <poll.h> header file. */
/* #undef HAVE_POLL_H */

/* Define to 1 if you have a working POSIX-style strerror_r function. */
/* #undef HAVE_POSIX_STRERROR_R */

/* Define to 1 if you have the <pthread.h> header file */
/* #undef HAVE_PTHREAD_H */

/* Define to 1 if you have the <pwd.h> header file. */
/* #undef HAVE_PWD_H */

/* Define to 1 if OpenSSL has the `SSL_set0_wbio` function. */
/* #undef HAVE_SSL_SET0_WBIO */

/* Define to 1 if you have the recv function. */
/* #undef HAVE_RECV */

/* Define to 1 if you have the select function. */
#define HAVE_SELECT 1

/* Define to 1 if you have the sched_yield function. */
/* #undef HAVE_SCHED_YIELD */

/* Define to 1 if you have the send function. */
/* #undef HAVE_SEND */

/* Define to 1 if you have the sendmsg function. */
/* #undef HAVE_SENDMSG */

/* Define to 1 if you have the 'fsetxattr' function. */
/* #undef HAVE_FSETXATTR */

/* fsetxattr() takes 5 args */
/* #undef HAVE_FSETXATTR_5 */

/* fsetxattr() takes 6 args */
/* #undef HAVE_FSETXATTR_6 */

/* Define to 1 if you have the `setlocale' function. */
/* #undef HAVE_SETLOCALE */

/* Define to 1 if you have the `setmode' function. */
/* #undef HAVE_SETMODE */

/* Define to 1 if you have the `setrlimit' function. */
/* #undef HAVE_SETRLIMIT */

/* Define to 1 if you have a working setsockopt SO_NONBLOCK function. */
/* #undef HAVE_SETSOCKOPT_SO_NONBLOCK */

/* Define to 1 if you have the sigaction function. */
/* #undef HAVE_SIGACTION */

/* Define to 1 if you have the siginterrupt function. */
/* #undef HAVE_SIGINTERRUPT */

/* Define to 1 if you have the signal function. */
#define HAVE_SIGNAL 1

/* Define to 1 if you have the sigsetjmp function or macro. */
/* #undef HAVE_SIGSETJMP */

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define to 1 if struct sockaddr_in6 has the sin6_scope_id member */
#define HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID 1

/* Define to 1 if you have the `socket' function. */
#define HAVE_SOCKET 1

/* Define to 1 if you have the socketpair function. */
/* #undef HAVE_SOCKETPAIR */

/* Define to 1 if you have the <stdatomic.h> header file. */
/* #undef HAVE_STDATOMIC_H */

/* Define to 1 if you have the <stdbool.h> header file. */
/* #undef HAVE_STDBOOL_H */

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the strcasecmp function. */
/* #undef HAVE_STRCASECMP */

/* Define to 1 if you have the strcmpi function. */
#define HAVE_STRCMPI 1

/* Define to 1 if you have the strdup function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the strerror_r function. */
/* #undef HAVE_STRERROR_R */

/* Define to 1 if you have the stricmp function. */
#define HAVE_STRICMP 1

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <stropts.h> header file. */
/* #undef HAVE_STROPTS_H */

/* Define to 1 if you have the strtok_r function. */
/* #undef HAVE_STRTOK_R */

/* Define to 1 if you have the strtoll function. */
#define HAVE_STRTOLL 1

/* Define to 1 if you have the memrchr function. */
/* #undef HAVE_MEMRCHR */

/* if struct sockaddr_storage is defined */
#define HAVE_STRUCT_SOCKADDR_STORAGE 1

/* Define to 1 if you have the timeval struct. */
#define HAVE_STRUCT_TIMEVAL 1

/* Define to 1 if you have the <sys/filio.h> header file. */
/* #undef HAVE_SYS_FILIO_H */

/* Define to 1 if you have the <sys/wait.h> header file. */
/* #undef HAVE_SYS_WAIT_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */
/* #undef HAVE_SYS_IOCTL_H */

/* Define to 1 if you have the <sys/param.h> header file. */
/* #undef HAVE_SYS_PARAM_H */

/* Define to 1 if you have the <sys/poll.h> header file. */
/* #undef HAVE_SYS_POLL_H */

/* Define to 1 if you have the <sys/resource.h> header file. */
/* #undef HAVE_SYS_RESOURCE_H */

/* Define to 1 if you have the <sys/select.h> header file. */
/* #undef HAVE_SYS_SELECT_H */

/* Define to 1 if you have the <sys/socket.h> header file. */
/* #undef HAVE_SYS_SOCKET_H */

/* Define to 1 if you have the <sys/sockio.h> header file. */
/* #undef HAVE_SYS_SOCKIO_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
/* #undef HAVE_SYS_TIME_H */

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/un.h> header file. */
/* #undef HAVE_SYS_UN_H */

/* Define to 1 if you have the <sys/utime.h> header file. */
#define HAVE_SYS_UTIME_H 1

/* Define to 1 if you have the <termios.h> header file. */
/* #undef HAVE_TERMIOS_H */

/* Define to 1 if you have the <termio.h> header file. */
/* #undef HAVE_TERMIO_H */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to 1 if you have the `utime' function. */
#define HAVE_UTIME 1

/* Define to 1 if you have the `utimes' function. */
/* #undef HAVE_UTIMES */

/* Define to 1 if you have the <utime.h> header file. */
/* #undef HAVE_UTIME_H */

/* Define to 1 if compiler supports C99 variadic macro style. */
#define HAVE_VARIADIC_MACROS_C99 1

/* Define to 1 if compiler supports old gcc variadic macro style. */
/* #undef HAVE_VARIADIC_MACROS_GCC */

/* Define to 1 if you have the windows.h header file. */
#define HAVE_WINDOWS_H 1

/* Define to 1 if you have the winsock2.h header file. */
#define HAVE_WINSOCK2_H 1

/* Define this symbol if your OS supports changing the contents of argv */
/* #undef HAVE_WRITABLE_ARGV */

/* Define to 1 if you have the ws2tcpip.h header file. */
#define HAVE_WS2TCPIP_H 1

/* Define to 1 if you need the lber.h header file even with ldap.h */
/* #undef NEED_LBER_H */

/* Define to 1 if you need the malloc.h header file even with stdlib.h */
/* #undef NEED_MALLOC_H */

/* Define to 1 if _REENTRANT preprocessor symbol must be defined. */
/* #undef NEED_REENTRANT */

/* cpu-machine-OS */
#define OS "Windows"

/* Name of package */
/* #undef PACKAGE */

/* Define to the address where bug reports for this package should be sent. */
/* #undef PACKAGE_BUGREPORT */

/* Define to the full name of this package. */
/* #undef PACKAGE_NAME */

/* Define to the full name and version of this package. */
/* #undef PACKAGE_STRING */

/* Define to the one symbol short name of this package. */
/* #undef PACKAGE_TARNAME */

/* Define to the version of this package. */
/* #undef PACKAGE_VERSION */

/* a suitable file to read random data from */
/* #undef RANDOM_FILE */

/*
 Note: SIZEOF_* variables are fetched with CMake through check_type_size().
 As per CMake documentation on CheckTypeSize, C preprocessor code is
 generated by CMake into SIZEOF_*_CODE. This is what we use in the
 following statements.

 Reference: https://cmake.org/cmake/help/latest/module/CheckTypeSize.html
*/

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* The size of `off_t', as computed by sizeof. */
#define SIZEOF_OFF_T 4

/* The size of `curl_off_t', as computed by sizeof. */
#define SIZEOF_CURL_OFF_T 8

/* The size of `curl_socket_t', as computed by sizeof. */
/* #undef SIZEOF_CURL_SOCKET_T */

/* The size of `size_t', as computed by sizeof. */
#define SIZEOF_SIZE_T 8

/* The size of `time_t', as computed by sizeof. */
#define SIZEOF_TIME_T 8

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define if you want to enable c-ares support */
/* #undef USE_ARES */

/* Define if you want to enable POSIX threaded DNS lookup */
/* #undef USE_THREADS_POSIX */

/* Define if you want to enable WIN32 threaded DNS lookup */
#define USE_THREADS_WIN32 1

/* if GnuTLS is enabled */
/* #undef USE_GNUTLS */

/* if Secure Transport is enabled */
/* #undef USE_SECTRANSP */

/* if mbedTLS is enabled */
/* #undef USE_MBEDTLS */

/* if BearSSL is enabled */
/* #undef USE_BEARSSL */

/* if WolfSSL is enabled */
/* #undef USE_WOLFSSL */

/* if libSSH is in use */
/* #undef USE_LIBSSH */

/* if libSSH2 is in use */
/* #undef USE_LIBSSH2 */

/* if libPSL is in use */
/* #undef USE_LIBPSL */

/* If you want to build curl with the built-in manual */
/* #undef USE_MANUAL */

/* if you want to use OpenLDAP code instead of legacy ldap implementation */
/* #undef USE_OPENLDAP */

/* if OpenSSL is in use */
/* #undef USE_OPENSSL */

/* Define to 1 if you don't want the OpenSSL configuration to be loaded
   automatically */
/* #undef CURL_DISABLE_OPENSSL_AUTO_LOAD_CONFIG */

/* to enable NGHTTP2  */
/* #undef USE_NGHTTP2 */

/* to enable NGTCP2 */
/* #undef USE_NGTCP2 */

/* to enable NGHTTP3  */
/* #undef USE_NGHTTP3 */

/* to enable quiche */
/* #undef USE_QUICHE */

/* Define to 1 if you have the quiche_conn_set_qlog_fd function. */
/* #undef HAVE_QUICHE_CONN_SET_QLOG_FD */

/* to enable msh3 */
/* #undef USE_MSH3 */

/* if Unix domain sockets are enabled  */
#define USE_UNIX_SOCKETS 1

/* Define to 1 if you are building a Windows target with large file support. */
#define USE_WIN32_LARGE_FILES 1

/* to enable SSPI support */
/* #undef USE_WINDOWS_SSPI */

/* to enable Windows SSL  */
/* #undef USE_SCHANNEL */

/* enable multiple SSL backends */
/* #undef CURL_WITH_MULTI_SSL */

/* Version number of package */
/* #undef VERSION */

/* Define to 1 if OS is AIX. */
#ifndef _ALL_SOURCE
#  undef _ALL_SOURCE
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* define this if you need it to compile thread-safe code */
/* #undef _THREAD_SAFE */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Type to use in place of in_addr_t when system does not provide it. */
#define in_addr_t unsigned long

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#undef inline
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* the signed version of size_t */
/* #undef ssize_t */

/* Define to 1 if you have the mach_absolute_time function. */
/* #undef HAVE_MACH_ABSOLUTE_TIME */

/* to enable Windows IDN */
/* #undef USE_WIN32_IDN */

/* Define to 1 to enable websocket support. */
/* #undef USE_WEBSOCKETS */

/* Define to 1 if OpenSSL has the SSL_CTX_set_srp_username function. */
/* #undef HAVE_OPENSSL_SRP */

/* Define to 1 if GnuTLS has the gnutls_srp_verifier function. */
/* #undef HAVE_GNUTLS_SRP */

/* Define to 1 to enable TLS-SRP support. */
/* #undef USE_TLS_SRP */