#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>     // socket
#include <sys/ioctl.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>

#define SERVER_PORT 80

#define MAXLINE 4096
#define SA struct sockaddr

#define BIG 1000000000UL
uint32_t counter = 0;

void * count_to_big(void *arg);
char *getHomePage(char *addr, int *bytesread);

int main() {
    pthread_t t;
    char *buf;
    int buflen;

    pthread_create(&t, NULL, count_to_big, NULL);
    buf = getHomePage("172.217.0.78", &buflen);
    pthread_join(t, NULL);

    printf("Done. Counter: %u, Received %d bytes\n", counter, buflen);
    printf("%s\n", buf);

    return 0;
}

char *getHomePage(char *addr, int *bytesread) {
    int sockfd, n;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char *buffer = malloc(MAXLINE);

    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
        return NULL;
        // err_n_die("Error while creating the socket!");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT); // host to network, short

    // string to binary representation for IP address
    if(inet_pton(AF_INET, addr, &servaddr.sin_addr) <= 0)
        return NULL;
        // err_n_die("inet_pton error for %s ", addr);

    if(connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
        return NULL;
        // err_n_die("connect failed!");

    // prepare the message
    //          request  path  protocol+version
    //                |    |    |
    sprintf(sendline, "GET /get HTTP/1.1\r\n\r\n");
    sendbytes = strlen(sendline);

    // send the request - making sure you send it all
    // this code is a bit fragile, as it bails if only 
    // some of the bytes are sent.
    // normally, you would want to retry, unless the return value was -1
    if(write(sockfd, sendline, sendbytes) != sendbytes)
        return NULL;
        // err_n_die("write error!");

    memset(buffer, 0, MAXLINE);
    // read server's response
    n = read(sockfd, buffer, MAXLINE-1);
    close(sockfd);
    if(n < 0)
        return NULL;

    *bytesread = n;
    return buffer;
}

void * count_to_big(void *arg) {
    for(uint32_t i = 0; i < BIG; i++) {
        counter++;
    }

    return NULL;
}
