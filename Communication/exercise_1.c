#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
A parent creates 3 processes 
first child process prints a message and exit with code 0
the others two children are in a infinite loop
the father after 3 seconds send a signal SIGUSR1 to the children
The children handle the message and print 
“received sig <sig>, from my parent  <pid>” and exit with code 1
*/
#define PID_SIZE 3

void handle_sigusr1(int sig) {
    printf("Received sig %d, from my parent %d\n", sig, getppid());
    exit(1);
}

int main(void) {
    // pid_t pid1, pid2, pid3;
    pid_t pids[PID_SIZE];

    // first child process
    pids[0] = fork();
    if (pids[0] == 0) {
        // First child prints and exits
        printf("First child process (PID %d) exiting...\n", getpid());
        exit(0);
    }

    // second child process
    pids[1] = fork();
    if (pids[1] == 0) {
        // signal function with kill signal and signal handler function as arguments
        signal(SIGUSR1, handle_sigusr1);
        while (1); // pause();  // Wait for signals
    }

    // third child process
    pids[2] = fork();
    if (pids[2] == 0) {
        // signal function with kill signal and signal handler function as arguments
        signal(SIGUSR1, handle_sigusr1);
        while (1); // pause();  // Wait for signals
    }

    // for (int i = 0; i < PID_SIZE; i++) {
    //     pids[i] = fork();
    //     if (pids[i] == 0) {
    //         if
    //         // signal function with kill signal and signal handler function as arguments
    //         signal(SIGUSR1, handle_sigusr1);
    //         while (1); // pause();  // Wait for signals
    //     }
    //     if (pids[i] < 0) {
    //         fprintf(stderr, "Fork failed\n");
    //         exit(1);
    //     }
    // }

    // Parent process waits for 3 seconds
    sleep(3);

    // kill function called with child process pids and kill signal
    // This triggers the signal function in the child processes
    printf("Parent (PID %d) sending SIGUSR1 to children...\n", getpid());
    kill(pids[1], SIGUSR1);
    kill(pids[2], SIGUSR1);

    // Waits for all child processes to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Parent process (PID %d) exiting...\n", getpid());
    return 0;
}

