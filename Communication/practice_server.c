#include <stdio.h>      // Standard I/O functions
#include <stdlib.h>     // Standard library functions
#include <string.h>     // String handling functions
#include <unistd.h>     // UNIX standard functions (close, read, write)
#include <arpa/inet.h>  // Definitions for internet operations (socket, bind, listen, accept)

#define PORT 8080  // Port number for server to listen on

int main(void) {
    int server_fd, new_socket; // declare server socket and new socket (for incoming requests) variables
    struct sockaddr_in server_addr; // The SOCKADDR_IN structure specifies a transport address and port for the AF_INET address family.
    int addrlen = sizeof(server_addr); // the length of the address
    char buffer[1024] = {0}; // Buffer to store received messages


    // Step 1: Create a TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Define server server_address structure
    server_addr.sin_family = AF_INET; // IPv4 address family
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections on any IP (localhost or network IP)
    server_addr.sin_port = htons(PORT); // Convert port number to network byte order

    // Step 3: Bind the socket to the IP and port
    if (bind(server_fd, (struct sockaddr*)&server_addr, addrlen) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Step 4: Put the server in a listening state (maximum 3 pending connections)
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on PORT: %d...\n", PORT);

    // Step 5: Accept an incoming connection from a client
    new_socket = accept(server_fd, (struct sockaddr*)&server_addr, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Step 6: Receive data from client
    read(new_socket, buffer, 1024);
    printf("Client: %s\n", buffer);

    // Step 7: Close the connection
    close(new_socket);
    close(server_fd);

    return 0;
}