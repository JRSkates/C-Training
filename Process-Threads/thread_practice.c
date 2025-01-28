#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// When you create a thread, it executes a function
void *routine() {
    // print a message
    printf("Test from threads\n");
    // wait 3 seconds
    sleep(3);
    // print end message
    printf("Thread finished\n");
    // return a value to indicate success
    return 0;  // void* return type is required for pthread_create() to work correctly. 0 means success.
}

int main(void) {
    // Define where information can be stored about the thread
    // We can declare moer than one thread like you would variables
    pthread_t t1, t2;

    // Initialize a thread with the _create function
    // First parameter is the address of the thread
    // Second parameter is the attributes (NULL in this case)
    // Third parameter is the function that will be executed by the thread
    // Fourth parameter is the argument passed to the function
    // Note: The function must return void* or use a void* pointer as its argument
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        // We have a conditonal to check for an error
        // As this function returns 0 if it is successful
        return 1;
    };

    if (pthread_create(&t2, NULL, &routine, NULL)!= 0) {
        return 2;
    };


    // We have to wait for the thread to finish it's execution
    if (pthread_join(t1, NULL) != 0) {
        return 3;
    };
    
    if (pthread_join(t2, NULL) != 0) {
        return 4;
    };

    return 0;
}