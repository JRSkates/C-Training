#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080  // Port number for server to listen on

int main(void) {
    int client_sock = 0;
    struct sockaddr_in serv_addr;  // Struct to store server address information
    char buffer[1024] = {0};       // Buffer to store server response
    int n = 0;

    // Step 1: Create a TCP socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Specify server address details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Step 3: Convert IP from string to binary form and store in serv_addr
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    // Step 4: Connect to the server
    if (connect(client_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    // Step 5: Send message to the server every 10 seconds
    while (n < 10) {
        time_t current_time;
        struct tm *time_info;
        char time_str[100];  // Fixed declaration

        // Get the current time
        time(&current_time);

        // Convert it to local time
        time_info = localtime(&current_time);

        // Format time as a readable string
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

        // Send formatted time string to server
        send(client_sock, time_str, strlen(time_str), 0);
        printf("Message sent to the server: %s\n", time_str);

        sleep(10);  // Wait for 10 seconds before sending again
        n++;
    }

    // Step 6: Close the socket
    close(client_sock);
    return 0;
}
