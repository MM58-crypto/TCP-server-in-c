#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
/*
#define MAX_REQUEST_SIZE_1024
*/
// error handling
void error(const char *msg) {
  perror(msg);
  exit(1);
}
//

int main() {

  struct sockaddr_in serv_addr;
  int sockfd, newsockfd, portno; // socket file descriptor, port number vars
  socklen_t address_len = sizeof(serv_addr);
  char buffer[256];


  // socket creation
  // params:
  // af_inet -> ipv4
  // sock_stream --> for tcp connections
 if ((sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0)) {
    printf(" An error occured when creating the socket");
    exit(1);

 }

 serv_addr.sin_family = AF_INET; // address family
 serv_addr.sin_port = htons(PORT); // specify port to listen on
 serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // allows server to a accept client on any interface


 if ((bind(sockfd, (struct sockaddr *) &serv_addr, address_len) < 0)) {
       printf("error in binding");

       exit(1);
}

 // listen params:
 // listen (int sockfd, int backlog) --> sockfd: created socket file descriptor,
 // backlog: max number og pending connections to be queued for the socket
 if (listen(sockfd, 5) < 0) {
   printf("error in listening");
   exit(1);
 }


/*
 while (1) {
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clienlen);

     char buffer[256];
     bzero(buffer, 256);
     read(newsockfd, buffer, 255);


  }
  listen(sockfd, 5);
*/
return 0;
}
