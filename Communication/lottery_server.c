/*
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

int main(void) {
    
    return 0;
}