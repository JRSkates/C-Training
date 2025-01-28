#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

// Define a mutex to ensure that only one thread can access the mails variable at a time
pthread_mutex_t mutex;

// When you create a thread, it executes a function
void *routine() {
    
    for (int i = 0; i < 1000000; i++) {
        // Lock the mutex before modifying the shared resource
        // If at ANY POINT a thread is executing the critical section
        // No other thread can execute the critical section
        pthread_mutex_lock(&mutex);
        // increment mails
        mails++;
        // Unlock the mutex after modifying the shared resource
        pthread_mutex_unlock(&mutex);
    }
    // wait 3 seconds
    // sleep(3);
    // return a value to indicate success
    return 0;  // void* return type is required for pthread_create() to work correctly. 0 means success.
}


int main(void) {
    // Define where information can be stored about the thread
    // We can declare more than one thread like you would variables
    // pthread_t t1, t2, t3, t4;

    // We can also create an array of threads
    pthread_t th[4];
    int i;

    // Initialize a mutex
    pthread_mutex_init(&mutex, NULL);

    // We can use a for loop to create multiple threads
    for (i = 0; i < 4; i++) {

        // Initialize a thread with the _create function
        // First parameter is the address of the thread
        // Second parameter is the attributes (NULL in this case)
        // Third parameter is the function that will be executed by the thread
        // Fourth parameter is the argument passed to the function
        // Note: The function must return void* or use a void* pointer as its argument
        if (pthread_create(&th[i], NULL, &routine, NULL)!= 0) {
            return 1;
        }

        printf("Thread %d has started\n", i);
    }

    // We then have a seperate loop to join the threads
    // This has to be in a different loop because otherwise the threads
    // will NOT run concurrently, they will run sequentially which is not what we want
    for (i = 0; i < 4; i++) {
        // We have to wait for the thread to finish it's execution
        // The second parameter is a pointer to an integer that will receive the exit status of the thread
        // In this case, NULL means we don't care about the exit status
        // Note: pthread_join() blocks the calling thread until the thread specified by the first parameter terminates
        // Returns 0 if it is successful, or an error number if it fails
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }

        printf("Thread %d has finished\n", i);
    }

    // Destroy the mutex when we're done using it
    pthread_mutex_destroy(&mutex);

    // Print the final count of mails
    printf("Number of mails: %d\n", mails);


    return 0;
}