// Ex1 Write a C programme:​
// The son process print a message like:​
// “I’m X, son of process Y” (X and Y are the PID and PPID)​
// The father print​
// “I’m the father. My Son is  : x”

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    pid_t pid; // Variable to store the process ID

    pid = fork(); // Create a new process

    if (pid == 0) {
        // Child process
        printf("I'm %d, son of process %d\n", getpid(), getppid());
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to finish

        // Print the PID of the son process
        // While in the child process, pid would just return 0 (true)
        // However here in the parent, it returns the PID of the child process
        printf("I'm the father. My Son is: %d\n", pid);
    }

    return 0;
}
