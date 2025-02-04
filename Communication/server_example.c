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
    struct sockaddr_in server_address;  // Struct to store server server_address information
    int addrlen = sizeof(server_address);
    char buffer[1024] = {0};  // Buffer to store received messages

    // Step 1: Create a TCP socket
    // Calls socket() to create a TCP socket (SOCK_STREAM).
    // Uses IPv4 addressing (AF_INET).
    // The protocol is set to 0, meaning TCP is selected automatically.
    // If the socket creation fails, it prints an error and exits.
                     // domain  type         protocol
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Define server server_address structure
    // The IPv4 server_address family is set (AF_INET).
    // INADDR_ANY allows the server to accept connections on any 
    // available network interface (like 127.0.0.1 or an actual IP).
    // The port number is converted from host byte order to network 
    // byte order using htons() to ensure proper communication.
    server_address.sin_family = AF_INET;         // IPv4
    server_address.sin_addr.s_addr = INADDR_ANY; // Accept connections on any IP (localhost or network IP)
    server_address.sin_port = htons(PORT);       // Convert port number to network byte order

    // Step 3: Bind the socket to the IP and port
    // This assigns the socket to the IP and port number specified in the server_address structure.
    // If the binding fails, the server will exit with an error message.
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Step 4: Put the server in a listening state (maximum 3 pending connections)
    // listen(server_fd, 3) tells the socket to start waiting for incoming connections.
    // The "3" means up to 3 client connections can be queued before they are accepted.
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Step 5: Accept an incoming connection from a client
    // accept() waits for a client to connect.
    // When a client connects, accept() returns a new socket (new_socket) just for that client.
    // The server can now communicate with the client using this new socket.
    // If it fails, it prints an error and exits.
    new_socket = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen);
    if (new_socket == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Step 6: Receive data from client
    // Reads data from the client into buffer.
    // The server then prints the received message
    read(new_socket, buffer, 1024);
    printf("Client: %s\n", buffer);

    // Step 7: Send response to client
    char *response = "Hello from server";
    send(new_socket, response, strlen(response), 0);

    // Step 8: Close the sockets
    // The server closes the connection with the client.
    // Finally, the main server socket is closed, stopping further connections.
    close(new_socket); // Close connection with the client
    close(server_fd);  // Close the server socket

    return 0;
}
