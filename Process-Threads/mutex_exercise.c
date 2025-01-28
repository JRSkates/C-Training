#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int database = 0;
int reader_count = 0;
pthread_mutex_t database_mutex;     // Protects database
pthread_mutex_t reader_mutex; // Protects reader

void *reader(void *arg) {
    int reader_id = *(int *)arg;

    // Continuous while loop
    while (1) {
        // Lock the reader mutex to safely update the reader count
        pthread_mutex_lock(&reader_mutex);
        reader_count++;

        // If this is the first reader, lock the database mutex
        if (reader_count == 1) {
            pthread_mutex_lock(&database_mutex);
        }

        // Unlock the reader mutex to allow other readers to access the database
        pthread_mutex_unlock(&reader_mutex);

        // Read from the database
        printf("Reader %d read database value: %d\n", reader_id, database);
        sleep(2);

        // Unlock reader_count mutex to update reader_count
        pthread_mutex_lock(&reader_mutex);
        reader_count--;
        if (reader_count == 0) {
            // Last reader unlocks the resource for the writers
            pthread_mutex_unlock(&database_mutex);
        }
        pthread_mutex_unlock(&reader_mutex);

        sleep(rand() % 3 + 1); // Simulate time between reads
    }

    pthread_exit(NULL);
}

void *writer(void *arg) {
    int writer_id = *(int *)arg;

    // Continuous while loop
    while (1) {
        // Lock the database mutex to prevent data corruption
        pthread_mutex_lock(&database_mutex);

        // Write to the database
        database++;
        printf("Writer %d wrote to database value: %d\n", writer_id, database);

        // Unlock the database mutex
        pthread_mutex_unlock(&database_mutex);

        sleep(rand() % 3 + 1); // Simulate time between writes
    }

    pthread_exit(NULL);
}

int main(void) {
    // initialize threads and index arrays
    pthread_t readers[5], writers[2];
    int reader_id[5], writer_id[2];
    int i;

    // initialize mutex
    pthread_mutex_init(&reader_mutex, NULL);
    pthread_mutex_init(&database_mutex, NULL);

    // create reader threads
    for (i = 0; i < 5; i++) {
        reader_id[i] = i;
        if (pthread_create(&readers[i], NULL, reader, &reader_id[i]) != 0) {
            printf("Error creating reader thread\n");
            return 1;
        }
    }

    // create writer threads
    for (i = 0; i < 2; i++) {
        writer_id[i] = i;
        if (pthread_create(&writers[i], NULL, writer, &writer_id[i]) != 0) {
            printf("Error creating writer thread\n");
            return 1;
        }
    }

    // join reader threads
    for (i = 0; i < 5; i++) {
        if (pthread_join(readers[i], NULL)!= 0) {
            printf("Error joining reader thread\n");
            return 2;
        }
    }

    // join writer threads
    for (i = 0; i < 2; i++) {
        if (pthread_join(writers[i], NULL)!= 0) {
            printf("Error joining writer thread\n");
            return 2;
        }
    }

    // Destroy
    pthread_mutex_destroy(&reader_mutex);
    pthread_mutex_destroy(&database_mutex);

    return 0;
}
