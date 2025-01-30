#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h> // For O_CREAT and O_EXCL

#define NUM_CARS 30
#define PARKING_SPOTS 10
#define SEMAPHORE_NAME "/parking_lot_semaphore"

sem_t *parking_lot;  // Named semaphore for parking spots

void* car(void* arg) {
    int car_id = *(int*)arg;
    
    printf("🚗 Car %d is trying to enter the parking lot...\n", car_id);
    sem_wait(parking_lot);  // Decrease available spots (wait for a spot)

    printf("✅ Car %d parked! 🚙 (Spot taken)\n", car_id);
    sleep(rand() % 60 + 1);  // Simulate parking time

    printf("⛔ Car %d is leaving... (Spot freed)\n", car_id);
    sem_post(parking_lot);  // Increase available spots

    free(arg);
    return NULL;
}

int main() {
    srand(time(NULL));  // Seed for random sleep times

    // Ensure previous semaphore instance is removed
    sem_unlink(SEMAPHORE_NAME);

    // Create a named semaphore with parking spots
    parking_lot = sem_open(SEMAPHORE_NAME, O_CREAT, 0644, PARKING_SPOTS);
    if (parking_lot == SEM_FAILED) {
        perror("Failed to open semaphore");
        return 1;
    }

    pthread_t cars[NUM_CARS];

    // Create car threads
    for (int i = 0; i < NUM_CARS; i++) {
        int* car_id = malloc(sizeof(int));
        *car_id = i + 1;
        if (pthread_create(&cars[i], NULL, car, car_id) != 0) {
            printf("Error creating thread\n");
            return 1;
        }
        sleep(3);  // Stagger car arrivals
    }

    // Join all car threads
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(cars[i], NULL);
    }

    // Cleanup
    sem_close(parking_lot);
    sem_unlink(SEMAPHORE_NAME);

    return 0;
}
