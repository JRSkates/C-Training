/*
Multiplexing allows a program to monitor multiple file descriptors (sockets) 
at the same time and act when any of them becomes ready for reading or writing.

Why use multiplexing?
A basic server using accept() can only handle one client at a time.
A multiplexed server can handle many clients at once, 
without creating multiple processes or threads.

Common Multiplexing Techniques
Technique	        Description
select()	        Monitors multiple sockets and checks if they are ready for reading/writing.
poll()	            Similar to select(), but handles large numbers of connections better.
epoll()	            More efficient than select() and poll(), used in Linux.

For simplicity, we will focus on select().

How select() Works
select() Monitors Multiple Sockets
You tell select() which sockets you want to monitor.
select() blocks until one of the sockets is ready to read or write.
When select() returns, you check which socket is ready and handle it.

File Descriptor Sets
fd_set is used to store a list of file descriptors (sockets) to monitor.

There are three types:
Set	        Purpose
readfds	    Monitors sockets ready for reading.
writefds	Monitors sockets ready for writing.
exceptfds	Monitors sockets with errors.

Steps to Create a Multiplexed TCP Server Using select()
Step	Function	        What It Does
1	    socket()	        Create a listening socket.
2	    bind()	            Bind it to an IP and port.
3	    listen()	        Start listening for clients.
4	    select()	        Wait for client connections and data.
5	    FD_SET()	        Add new sockets to the monitored set.
6	    accept()	        Accept new client connections.
7	    recv() / send()	    Read and write data.
8	    close()	            Close disconnected clients.
*/

#include <stdio.h>      // Standard I/O functions (printf, perror)
#include <stdlib.h>     // Standard library functions (exit)
#include <string.h>     // String handling functions (strlen, memset)
#include <unistd.h>     // UNIX system calls (close, read, write)
#include <arpa/inet.h>  // Internet operations (socket, bind, listen, accept, inet_ntoa)
#include <sys/select.h> // For using select() system call

#define PORT 8080        // Port number on which the server will listen
#define MAX_CLIENTS 10   // Maximum number of clients the server can handle simultaneously

int main() {
    int server_fd, new_socket;     // Server socket descriptor and new client socket descriptor
    int client_socket[MAX_CLIENTS]; // Array to track connected client sockets
    int max_sd, sd, activity, i, valread; // Variables for socket management
    struct sockaddr_in address;    // Structure to hold server address information
    fd_set readfds;                // File descriptor set for select()
    char buffer[1024];             // Buffer to store data received from clients

    // Step 1: Initialize all client sockets to 0 (indicating they are not in use)
    for (i = 0; i < MAX_CLIENTS; i++)
        client_socket[i] = 0;  // Set all client sockets to 0 (empty)

    // Step 2: Create the main server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation failed"); // Print error if socket creation fails
        exit(EXIT_FAILURE);
    }

    // Step 3: Bind the socket to an IP address and port
    address.sin_family = AF_INET;          // IPv4 address family
    address.sin_addr.s_addr = INADDR_ANY;  // Accept connections on any network interface
    address.sin_port = htons(PORT);        // Convert port number to network byte order

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed"); // Print error if binding fails
        exit(EXIT_FAILURE);
    }

    // Step 4: Put the server in listening mode to accept incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed"); // Print error if listening fails
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Step 5: Main loop to handle incoming connections and client messages
    while (1) {
        // Step 6: Clear and reset the file descriptor set
        FD_ZERO(&readfds);             // Clear the set before adding file descriptors
        FD_SET(server_fd, &readfds);   // Add the server socket to the set
        max_sd = server_fd;            // Initialize max_sd with the server socket descriptor

        // Step 7: Add active clients' sockets to the file descriptor set
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];  // Get the socket descriptor of the i-th client

            // If the socket is valid, add it to the read set
            if (sd > 0) FD_SET(sd, &readfds);

            // Update max_sd to the highest file descriptor value
            if (sd > max_sd) max_sd = sd;
        }

        // Step 8: Wait for activity on any socket using select()
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        // If select() returns an error, print an error message
        if ((activity < 0)) {
            perror("Select error");
        }

        // Step 9: Check if there's an incoming connection on the server socket
        if (FD_ISSET(server_fd, &readfds)) {
            socklen_t addrlen = sizeof(address);
            
            // Accept the new connection from a client
            new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
            if (new_socket < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // Print information about the new connection
            printf("New connection, socket fd: %d, IP: %s, Port: %d\n",
                   new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            // Step 10: Add new client to client_socket array
            for (i = 0; i < MAX_CLIENTS; i++) {
                // If an empty slot is found in the array, store the new socket descriptor
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    break;
                }
            }
        }

        // Step 11: Check all connected clients for incoming data
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i]; // Get the socket descriptor of the i-th client

            // If the client socket has activity, process its message
            if (FD_ISSET(sd, &readfds)) {
                valread = read(sd, buffer, 1024); // Read data from client
                if (valread == 0) {
                    // Step 12: Handle client disconnection
                    printf("Client disconnected, socket fd: %d\n", sd);
                    close(sd);        // Close the client socket
                    client_socket[i] = 0; // Remove the socket from the tracking array
                } else {
                    // Step 13: Process and echo the received message
                    buffer[valread] = '\0';  // Null-terminate the string
                    printf("Client %d: %s\n", sd, buffer); // Print the received message
                    send(sd, buffer, strlen(buffer), 0);   // Echo the message back to the client
                }
            }
        }
    }

    return 0;
}

/*
Step-by-Step Execution Summary
Step	    Function	                                    What It Does
1	        Initialize client_socket[]	                    Set all client slots to 0 (indicating they are free).
2	        socket()	                                    Create a TCP socket.
3	        bind()	                                        Bind the socket to an IP and port.
4	        listen()	                                    Start listening for incoming client connections.
5	        FD_ZERO()	                                    Clear the file descriptor set.
6	        FD_SET(server_fd, &readfds)	                    Add the server socket to the monitoring set.
7	        Loop through clients and FD_SET(sd, &readfds)	Add active client sockets to the monitoring set.
8	        select()	                                    Wait for activity on any socket.
9	        FD_ISSET(server_fd, &readfds)	                Check if a new client is trying to connect.
10	        accept()	                                    Accept the new client connection.
11	        Loop through clients & FD_ISSET(sd, &readfds)   Check each client for incoming data.
12	        read()	                                        Read data from the client.
13	        send()	                                        Echo the message back to the client.
14	        close()	                                        Close disconnected client sockets.
*/