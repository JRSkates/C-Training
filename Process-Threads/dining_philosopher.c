#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <fcntl.h>

/*
The Dining Philosopher Problem ​

5 Philosophers sit around a table with 5 shared chopsticks​

Each philosopher follows a cycle of thinking (waiting), 
picking up chopsticks, eating, and putting down chopsticks.​

A philosopher needs two chopsticks to eat.​
A philosopher must pick up both chopsticks before eating.​
If a chopstick is already in use, the philosopher must wait.​
Philosophers should avoid holding one chopstick indefinitely.

Create multiple philosopher threads, each representing a philosopher at the table.​

Simulate the following:​
Each philosopher thread "thinks" for a random period by printing a message (e.g., "Philosopher X is thinking").​
Each philosopher thread "picks up chopsticks", prints a message (e.g., "Philosopher X is picking up chopsticks").​
Each philosopher thread "eats" for a random period by printing a message (e.g., "Philosopher X is eating").​
After eating, each philosopher thread "puts down chopsticks" and goes back to thinking.​
Make each philosopher sleep for a random amount of time to simulate thinking and eating.​

Ensure proper synchronization:​
A philosopher must pick up both chopsticks before eating.​
A chopstick can only be used by one philosopher at a time.​
Philosophers must not hold one chopstick indefinitely, preventing deadlock.​

Implement a strategy (e.g., mutex locks or semaphores) to ensure fairness and avoid starvation.​
*/ 

#define NUM_OF_PHILOSOPHERS 5
#define NUM_OF_CHOPSTICKS 5
#define CHOPSTICK_SEMAPHORE "/chopstick_semaphore"

sem_t *chopsticks[NUM_OF_CHOPSTICKS];

void* philosopher(void *args) {
    int philosopher_id = *(int*)args;
    int left_chopstick = philosopher_id;
    int right_chopstick = (philosopher_id + 1) % NUM_OF_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking...\n", philosopher_id + 1);
        sleep(rand() % 3 + 1);

        // Pick up left chopstick
        sem_wait(chopsticks[left_chopstick]);
        printf("Philosopher %d picked up left chopstick (%d)\n", philosopher_id + 1, left_chopstick);

        // Pick up right chopstick
        sem_wait(chopsticks[right_chopstick]);
        printf("Philosopher %d picked up right chopstick (%d)\n", philosopher_id + 1, right_chopstick);

        // Eat
        printf("Philosopher %d is eating...\n", philosopher_id + 1);
        sleep(rand() % 3 + 1);

        // Put down chopsticks
        sem_post(chopsticks[left_chopstick]);
        printf("Philosopher %d put down left chopstick (%d)\n", philosopher_id + 1, left_chopstick);

        sem_post(chopsticks[right_chopstick]);
        printf("Philosopher %d put down right chopstick (%d)\n", philosopher_id + 1, right_chopstick);
    }

    free(args);
    return NULL;
}
int main() {
    srand(time(NULL));  
    // Ensure previous semaphore instances are removed
    for (int i = 0; i < NUM_OF_PHILOSOPHERS; i++) {
        char sem_name[20];
        sprintf(sem_name, "/chopstick_%d", i);
        sem_unlink(sem_name);
    }

    int i;
    
    // Declear philosopher threads
    pthread_t philosopher_threads[NUM_OF_PHILOSOPHERS];

    // Initialize semaphores for each chopstick
    for (i = 0; i < NUM_OF_CHOPSTICKS; i++) {
        char sem_name[20];
        sprintf(sem_name, "/chopstick_%d", i);
        chopsticks[i] = sem_open(sem_name, O_CREAT, 0644, 1);
    
        if (chopsticks[i] == SEM_FAILED) {
            perror("Failed to open semaphore");
            return 1;
        }

        // // Debug: Print semaphore name and its value
        // int sem_val;
        // sem_getvalue(chopsticks[i], &sem_val);
        // printf("Chopstick %d: Address=%p, Initial Value=%d\n", i, (void *)chopsticks[i], sem_val);
    }


    // Create philosopher threads and join them to the main thread
    for(i = 0; i < NUM_OF_PHILOSOPHERS; i++) {
        int *philosopher_id = malloc(sizeof(int));
        *philosopher_id = i;
        if (pthread_create(&philosopher_threads[i], NULL, philosopher, philosopher_id) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    for (i = 0; i < NUM_OF_PHILOSOPHERS; i++) {
        if (pthread_join(philosopher_threads[i], NULL) != 0) {
            perror("Error joining thread");
            return 2;
        }
    }

    // Cleanup semaphore
    for (int i = 0; i < NUM_OF_PHILOSOPHERS; i++) {
        char sem_name[20];
        sprintf(sem_name, "/chopstick_%d", i);
        sem_unlink(sem_name);
        sem_close(chopsticks[i]);
    }
}