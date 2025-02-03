// Steps to Create a TCP Server
// A server follows these steps:

// Step	    Function	        What It Does
// 1	    socket()	        Create a socket.
// 2	    bind()	            Assign an IP + port to the socket.
// 3	    listen()	        Wait for client connections.
// 4	    accept()	        Accept incoming connections.
// 5	    recv() / send()	    Read and write data.
// 6	    close()	            Close the connection.

#include <stdio.h>      // Standard I/O functions
#include <stdlib.h>     // Standard library functions
#include <string.h>     // String handling functions
#include <unistd.h>     // UNIX standard functions (close, read, write)
#include <arpa/inet.h>  // Definitions for internet operations (socket, bind, listen, accept)

#define PORT 8080  // Port number for server to listen on

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;  // Struct to store server address information
    int addrlen = sizeof(address);
    char buffer[1024] = {0};  // Buffer to store received messages

    // Step 1: Create a TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Define server address structure
    address.sin_family = AF_INET;         // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections on any IP (localhost or network IP)
    address.sin_port = htons(PORT);       // Convert port number to network byte order

    // Step 3: Bind the socket to the IP and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Step 4: Put the server in a listening state (maximum 3 pending connections)
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Step 5: Accept an incoming connection from a client
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Step 6: Receive data from client
    read(new_socket, buffer, 1024);
    printf("Client: %s\n", buffer);

    // Step 7: Send response to client
    char *response = "Hello from server";
    send(new_socket, response, strlen(response), 0);

    // Step 8: Close the sockets
    close(new_socket); // Close connection with the client
    close(server_fd);  // Close the server socket

    return 0;
}
