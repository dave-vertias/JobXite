#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


/*
struct in_addr {
    uint32_t s_addr;
};

struct in6_addr {
    unsigned char s6_addr[16]; //IPv6 Address
};

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct sockaddr_in {
    short int sin_family;
    unsigned short int sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[8];
};

struct sockaddr_in6 {
    u_int16_t sin6_family;
    u_int16_t sin6_port;
    u_int32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    u_int32_t sin6_scope_id;
};

struct addrinfo {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    size_t ai_addrlen;
    struct sockaddr *ai_addr;
    char *ai_canonname;
};

struct sockaddr_storage {
    sa_family_t ss_family;

    char    __ss_pad1[_SS_PADSIZE];
    int64_t __ss_align;
    char    __ss_pad1[_SS_PADSIZE];
};
*/

int python_exec(){
    system("./pydb.sh");
    return 0;
}

int main(int argc, char *argv[]){

    int status;
    struct addrinfo hints, *res, *p;
    const char IP[13] = "192.168.1.65";
    const char port[5] = "5000";
    char ipstr[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

   if((status = getaddrinfo(IP, port, &hints, &res)) != 0){
       fprintf(stderr, "Damn something went wrong!: %s", gai_strerror(status));
       exit(1);
   }

   for(p = res; p != NULL; p = p->ai_next){
       void *addr;
       char *ipver;

       if(p->ai_family == AF_INET){
           struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
           addr = &(ipv4->sin_addr);
           ipver = "IPv4";
       } else {
           struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
           addr = &(ipv6->sin6_addr);
           ipver = "IPv6";
       }

       inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
       printf("%s:%s \n", ipver,ipstr);
   }

   freeaddrinfo(res);


    return 0;
}
