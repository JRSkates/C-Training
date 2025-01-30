#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// A semaphore is a synchronization mechanism that
// Controls access to shared resources (e.g., the counter in this example)
// Works like a counter, keeping track of how many threads can access a resource

// Uses two key operations:
// sem_wait() (P operation) → Decrements the semaphore (blocks if the value is 0)
// sem_post() (V operation) → Increments the semaphore (unblocks a waiting thread)

#define SEMAPHORE_NAME "/my_named_semaphore"
#define NUM_THREADS 3

sem_t *semaphore;  // Use a pointer for named semaphores
short counter = 0;

void* thread(void* arg) {
    // Wait on semaphore
    // The first thread (e.g., t1) calls sem_wait():
    // The semaphore value is 1, so t1 decrements it to 0 and enters the critical section.
    // t1 runs its code (counter updates, sleep(4), etc.).

    // The second thread (t2) also calls sem_wait():
    // But now, the semaphore value is 0 (since t1 has it).
    // t2 blocks (waits) until t1 releases the semaphore. 
    sem_wait(semaphore);
    // Critical section 
    printf("\nEntered Thread...\n");

    counter++;
    printf("Counter before sleep: %d\n", counter);
    
    printf("Paused...\n");
    sleep(3);

    counter++;
    printf("Counter after sleep: %d\n", counter);
    
    printf("Just Exiting...\n");
    sleep(2);
    // After the 4 sleep and critical code is done, t1 calls sem_post(), which:
    // Increments the semaphore back to 1.
    // Unblocks t2, allowing it to enter the critical section.
    sem_post(semaphore);

    return NULL;
}

int main() {
    int i;
    printf("Counter: %d\n", counter);

    // Ensure previous semaphore instances are removed
    // this ensures that an old named semaphore doesn’t interfere with a new run
    sem_unlink(SEMAPHORE_NAME);

    // Create named semaphore (O_CREAT: create if it doesn’t exist, 0644: permission, 1: initial value)
    // The initial value of 1 means:
    // Only one thread can enter the critical section at a time
    // This acts like a mutex (binary semaphore)
    semaphore = sem_open(SEMAPHORE_NAME, O_CREAT, 0644, 1);
    if (semaphore == SEM_FAILED) {
        perror("Failed to open semaphore");
        return 1;
    }

    // Create threads
    pthread_t threads[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread, NULL);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nFinal Counter: %d\n", counter);

    // Close and remove named semaphore
    sem_close(semaphore);
    sem_unlink(SEMAPHORE_NAME);

    return 0;
}