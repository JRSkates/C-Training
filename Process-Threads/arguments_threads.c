#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*
Create 10 threads

Each taking a unique prime from the primes array and print it on the screen
*/

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
pthread_mutex_t mutex;

void *print_prime(void *arg) {
    sleep(1);

    int index = *(int*) arg;
    printf("%d\n", primes[index]);

    free(arg);
    return 0; // void* return type is required for pthread_create() to work correctly. 0 means success.
}

int main(void) {
    // Create 10 threads
    pthread_t threads[10];
    // int thread_ids[10];
    int i;

    // Create and start the threads with unique primes from the primes array
    for (i = 0; i < 10; i++) {
        // thread_ids[i] = i;
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&threads[i], NULL, &print_prime, a) != 0) {
            printf("Error creating thread\n");
            return 1;
        };
    }

    // Wait for all threads to finish
    for (i = 0; i < 10; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread\n");
            return 2;
        };
    }

    return 0;
}