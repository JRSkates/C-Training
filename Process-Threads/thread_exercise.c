#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

/*
Create 4 threads , you give an integer parameter <arg> starting from 1 to NTHREADS​

Each thread runs the same code: ​

Print "I’m thread <arg>", and do this 4 times​

After each print, the thread goes to sleep for <arg> seconds. 
Sleep(1) - thread sleeps for one second.​

After each thread has completed 4 iterations, they should call pthread_exit
*/

void *thread_function(void *arg) {
    int id = *(int*)arg;
    int i;

    for (i = 0; i < 4; i++) {
        printf("I'm thread %d\n", id);
        sleep(id);
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[4];
    int thread_args[4];

    for (i = 0; i < 4; i++) {
        thread_args[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    }

    // Join only the second thread (threads[1])
    // if (pthread_join(threads[1], NULL) == 0) {
    //     printf("Successfully joined thread 2\n");
    // } else {
    //     printf("Failed to join thread 2\n");
    // }

    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}