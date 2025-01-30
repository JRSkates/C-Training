#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

// Producers: These threads create data (or items) and place them into the buffer.
// Consumers: These threads take data (or items) out of the buffer to process it

// The Challenge​
// The buffer has a fixed size, meaning:​
// Producers must wait if the buffer is full before adding more items.
// Consumers must wait if the buffer is empty before taking items

// Create multiple producer threads and consumer threads.​

// Simulate the following:​
// Each producer thread "produces" an item by printing a message (e.g., "Producer X produced item Y").​
// Each consumer thread "consumes" an item by printing a message (e.g., "Consumer Z consumed item Y").​
// Make each thread sleep for a random amount of time to simulate the time taken for producing or consuming an item.​

// Ensure proper synchronization:​
// Producers must wait if the buffer is full.​
// Consumers must wait if the buffer is empty.​
// Use a semaphore to achieve this

#define BUFFER_SIZE 10
#define PRODUCER_NUM 5
#define CONSUMER_NUM 5

sem_t *consumer_sem;
sem_t *producer_sem;
// sem_t *buffer_empty;

int buffer = 0;
int producer_debt = 5;
int in = 0;
int out = 0;


void* producer(void* args) {
    int producer_id = *(int*)args;

    while (1) {
        // If buffer is full, wait for more space to be available
        sem_wait(producer_sem);
        //if (buffer < 10) {
            buffer++;
            printf("Producer: %d produced item, buffer at: %d\n", producer_id, buffer);
            // Increment consumer semaphore to indicate more buffer is available
            sem_post(consumer_sem);
        //} else {
        //    printf("Producer: %d buffer full, cannot produce item\n", producer_id);
        //}
        sleep(rand() % 6 + 1);
    }
    
    free(args);
    return NULL;
}

void* consumer(void* args) {
    int consumer_id = *(int*)args;
    while (1) {
        // If buffer is empty, wait for more items to be produced
        sem_wait(consumer_sem);

        printf("Consumer: %d taking from buffer...\n", consumer_id);
        buffer--;
        printf("Consumer: %d took from buffer, buffer at: %d\n", consumer_id, buffer);
        sleep(rand() % 6 + 1);

        // Increment producer semaphore to indicate 
        sem_post(producer_sem);
    }

    free(args);
    return NULL;
}

int main() {
    sem_unlink("/consumer_semaphore");
    sem_unlink("/producer_semaphore");

    int i;
    srand(time(NULL));

    printf("Starting program, buffer at: %d\n", buffer);

    // Define the threads
    pthread_t producer_threads[PRODUCER_NUM], consumer_threads[CONSUMER_NUM];

    // Create consumer semaphore
    consumer_sem = sem_open("/consumer_semaphore", O_CREAT, 0644, 0);
    if (consumer_sem == SEM_FAILED) {
        perror("Failed to open consumer semaphore");
        return 1;
    }

    // Create producer semaphore
    producer_sem = sem_open("/producer_semaphore", O_CREAT, 0644, BUFFER_SIZE);
    if (producer_sem == SEM_FAILED) {
        perror("Failed to open producer semaphore");
        return 1;
    }

    // Create producer threads
    for(i = 0; i < PRODUCER_NUM; i++) {
        int* producer_id = malloc(sizeof(int));
        *producer_id = i + 1;
        if (pthread_create(&producer_threads[i], NULL, producer, producer_id)) {
            printf("Error creating producer thread\n");
            return 1;
        }
    }

    // Create consumer threads
    for(i = 0; i < CONSUMER_NUM; i++) {
        int* consumer_id = malloc(sizeof(int));
        *consumer_id = i + 1;
        if (pthread_create(&consumer_threads[i], NULL, consumer, consumer_id)) {
            printf("Error creating consumer thread\n");
            return 1;
        }
        sleep(3);
    }

    // Join producer threads
    for(i = 0; i < PRODUCER_NUM; i++) {
        if (pthread_join(producer_threads[i], NULL)) {
            printf("Error joining producer thread\n");
            return 2;
        }
    }

    // Join consumer threads
    for(i = 0; i < CONSUMER_NUM; i++) {
        if (pthread_join(consumer_threads[i], NULL)) {
            printf("Error joining consumer thread\n");
            return 2;
        }
    }

    // Cleanup
    sem_close(consumer_sem);
    sem_close(producer_sem);
    sem_unlink("/consumer_semaphore");
    sem_unlink("/producer_semaphore");
    return 0;
}