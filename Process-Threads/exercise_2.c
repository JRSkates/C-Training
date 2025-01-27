/* 
Ex2 Write a C programme:​

Create a son process​

The son print “I’m the son Y” and terminate with the return status 1​

The father wait for the termination of the son, 
and after It will print the status of the terminated son​

Extra: Try to terminate the son in a involuntary way, 
and check if the son can detect it​

Change the programme that the father create N sons, 
and wait all the sons and print their status
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Create a son process
    pid_t pid = fork();
    // printf("%d\n", pid);

    // If the fork() function returns 0, it means that we are in the child process
    if(pid == 0) {
        printf("I'm the son %d\n", getpid());
        // Exit son process with status 1
        exit(1);
    } else {
        int status;
        // Wait for son process to finish
        wait(&status);
        // Print the status of the terminated son
        printf("Son %d terminated with status %d\n", pid, WIFEXITED(status));
    }
    
    return 0;
}