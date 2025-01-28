#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

// /*

// A shared database is accessed by two types of processes:​

// Readers: Processes that only need to read the data.​
// Writers: Processes that modify (write to) the data.​

// To ensure data consistency and avoid conflicts, the following rules must be followed:​
// - Multiple readers can access the database at the same time (read concurrently).​
// - Only one writer can access the database at a time.​
// - If a writer is writing to the database, no reader should be able to access it.

// Exercise:​
// Write a multithreaded program in C to implement the readers-writers problem using mutex locks.
// */

int database = 0;
pthread_mutex_t mutex;

/// @brief 
/// @param reader_ptr
/// @return 
void *reader_function(void *reader_ptr) {
    int reader_id = *((int *)reader_ptr);

    // Read data from shared resource
    printf("Reader %d is reading...\n", reader_id);
    printf("Data: %d\n", database);
    sleep(3);

    // Release lock for shared resource

    pthread_exit(NULL);
}

/// @brief 
/// @param writer_ptr 
/// @return 
void *writer_function(void *writer_ptr) {
    int writer_id = *((int *)writer_ptr);
    pthread_mutex_init(&mutex, NULL);

    pthread_mutex_lock(&mutex); // Lock the database

    printf("Writer %d is writing...\n", writer_id);
    database++;
    sleep(5);

    pthread_mutex_unlock(&mutex); // Unlock the database

    pthread_mutex_destroy(&mutex); // Destroy the mutex lock
    pthread_exit(NULL);
}

int main() {

    // Create reader and writer threads
    pthread_t reader_thread[5];
    pthread_t writer_thread[2];
    int reader_id[5];
    int writer_id[2];

    // Create writer threads
    for (int i = 0; i < 2; i++) {
        writer_id[i] = i + 1;
        pthread_create(&writer_thread[i], NULL, writer_function, &writer_id[i]);
        pthread_join(writer_thread[i], NULL);
    }

    // Create reader threads
    for (int i = 0; i < 5; i++) {
        reader_id[i] = i + 1;
        pthread_create(&reader_thread[i], NULL, reader_function, &reader_id[i]);
    }

    // Wait for reader threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(reader_thread[i], NULL);
    }

    // Wait for writer threads to finish
    // for (int i = 0; i < 3; i++) {
    //     pthread_join(writer_thread[i], NULL);
    // }

    return 0;
}
