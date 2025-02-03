// What is a Socket?
// A socket is like a virtual endpoint that allows processes to 
// communicate over a network (or even on the same machine).

// Think of it like:
// A telephone: You dial a number (IP address + port), and the receiver picks up.
// A mailbox: You send a letter (data) to an address (IP + port), and the recipient reads it.
// Sockets allow:

// Client-Server communication over TCP/IP.
// Inter-process communication (IPC) on the same machine (Unix Domain Sockets)

// Key Concepts in Sockets
// Term	            Meaning
// Socket	        A virtual communication endpoint (like a phone).
// IP Address	    The address of a machine (like a phone number).
// Port	            A unique number identifying an application on a machine (like a phone extension).
// Protocol	        The rules of communication (TCP = reliable, UDP = fast but unreliable).
// Binding	        Assigning a socket to a specific IP + port (like getting a phone number).
// Listening	    Waiting for incoming connections (like waiting for a call).
// Accepting	    Handling an incoming connection (like answering a call).
// Connecting	    A client trying to establish communication with a server.

// How It Works

// Server Side:
// Creates a socket with socket().
// Binds the socket to a port (bind()).
// Listens for connections (listen()).
// Accepts a client connection (accept()).
// Receives data (read()).
// Sends a response (send()).
// Closes the socket.

// Client Side:
// Creates a socket with socket().
// Connects to the server (connect()).
// Sends a message (send()).
// Receives the server response (read()).
// Closes the connection.
 

// Understanding Binding, Ports, and IP
// Binding (bind()): Assigns an IP + port to the socket.
// Listening (listen()): Waits for client connections.
// Accepting (accept()): Accepts incoming connections.
// Why Use INADDR_ANY?

// address.sin_addr.s_addr = INADDR_ANY;
// Allows the server to accept connections on any available network interface.

