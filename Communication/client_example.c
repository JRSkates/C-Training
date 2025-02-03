// Steps to Create a TCP Client
// A client follows these steps:

// Step	    Function	        What It Does
// 1	    socket()	        Create a socket.
// 2	    connect()	        Connect to the server.
// 3	    send() / recv()	    Send and receive data.
// 4	    close()	            Close the connection.

#include <stdio.h>      // Standard I/O functions
#include <stdlib.h>     // Standard library functions
#include <string.h>     // String handling functions
#include <unistd.h>     // UNIX standard functions (close, read, write)
#include <arpa/inet.h>  // Definitions for internet operations (socket, connect, send, recv)

#define PORT 8080  // Port number where the server is listening

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;  // Struct to store server address information
    char *message = "Hello from client";  // Message to send to server
    char buffer[1024] = {0};  // Buffer to store server response

    // Step 1: Create a TCP socket
    // Calls socket() to create a TCP socket (SOCK_STREAM).
    // Uses IPv4 addressing (AF_INET).
    // The protocol is set to 0, meaning TCP is selected automatically.
    // If the socket creation fails, it prints an error and exits.
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Specify server address details
    // The IPv4 address family is set (AF_INET).
    // htons(PORT) converts the port number to network byte order for compatibility
    serv_addr.sin_family = AF_INET;       // IPv4
    serv_addr.sin_port = htons(PORT);     // Convert port number to network byte order

    // Convert IP from string to binary form and store in serv_addr
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        exit(EXIT_FAILURE);
    }

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    // Step 4: Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");

    // Step 5: Receive response from server
    read(sock, buffer, 1024);
    printf("Server: %s\n", buffer);

    // Step 6: Close the socket
    close(sock);

    return 0;
}
