#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <arpa/inet.h>
#include <netinet/in.h>

int main (int argc, char** argv) {
  if (argc != 3) {
    printf("usage: ./server <server_ipv4> <server_port>\n");
    return -1;
  } else {
    const char* server_greeting = "Greetings. welcome to my TCP chat.\n";
    const char* host = argv[1];
    const int port = atoi(argv[2]);

    // create the server socket
    const int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, host, &(server_address.sin_addr));

    // bind the socket to our specified host and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    listen(server_socket, 5);
    while(1) {
      usleep(250 * 1000);
      int client_socket = accept(server_socket, NULL, NULL);
      send(client_socket, server_greeting, sizeof(server_greeting), 0);
      close(client_socket);
    }
    return 0; 
  }
}
