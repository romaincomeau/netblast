#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main (int argc, char** argv) {
  if (argc != 3) {
    printf("usage: ./client <server_ipv4> <server_port>\n");
    return -1;
  } else {

    const char* host = argv[1];
    const int port = atoi(argv[2]);
    const int socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, host, &(server_address.sin_addr));

    int connection_status =
      connect(socket_desc, (struct sockaddr*) &server_address, sizeof(server_address));

    if (connection_status < 0) {
      // error
      printf("netblast: error connecting to server\n");
      return -1;
    } else {
      char server_buffer[1024];
      recv(socket_desc, &server_buffer, sizeof(server_buffer), 0);
      printf("server: %s\n", server_buffer);
      close(socket_desc);
      return 0;
    }
  }
}
