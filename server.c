#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#include <pthread.h>

int main () {
  
  char server_message[1024] = "You have reached the server!\n";
  
  // create the server socket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // define the server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // bind the socket to our specified ip and port
  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

  // TODO: what does 5 do?
  listen(server_socket, 5);

  // accept a client
  int client_socket = accept(server_socket, NULL, NULL);

  send(client_socket, server_message, sizeof(server_message), 0);

  close(client_socket);
  close(server_socket);
  return 0;
}
