// Pipe

// Pipe is a tool to communicate between processes (one direction)
// There is read, write and close
// Remeber to close the side that you don't need (fd[0] input, fd[1] output)


// Socket

// Communication between processes (also in different computers)
// It’s an interface that can be used with different network protocol
// Socket is identify with an IP and a port
// It’s implemented from the OS

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int socket(int domain, int type, int protocol);

// domain: protocol family
// type
// AF_LOCAL local communication
// AF_INET – Protocolli IPv4, TCP e UDP
// type: tipologia di socket  
// SOCK_STREAM  guarantee delivery (TCP) 
// SOCK_DGRAM – no need connection (UDP)
// Protocol always 0

// struct sockaddr_in {
//     sa_family_t sin_family;
//     in_port_t sin_port;
//     struct in_addr sin_addr;
// };