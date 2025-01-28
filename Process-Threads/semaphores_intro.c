#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void* thread(void* arg)
{
    // Wait on semaphore
    sem_wait(&semaphore);
    printf("\nEntered..\n");

    // Critical section
    sleep(4);

    // Signal semaphore
    printf("\nJust Exiting...\n");
    sem_post(&semaphore);

    return NULL;
}

int main()
{
    // Initialize semaphore with value 1 (binary semaphore)
    sem_init(&semaphore, 0, 1);

    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, thread, NULL);
    pthread_create(&t2, NULL, thread, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

