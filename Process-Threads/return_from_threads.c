#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* roll_dice() {
    int dice_roll = (rand() % 6) + 1;
    int * result = malloc(sizeof(int));
    *result = dice_roll;
    printf("Dice roll: %d\n", dice_roll);
    return (void*) result;
}

int main(void) {
    int* res;
    srand(time(NULL)); // Seed the random number generator with the current time
    pthread_t thread;

    if (pthread_create(&thread, NULL, roll_dice, NULL) != 0) {
        printf("Error creating thread\n");
        return 1;
    };


    if (pthread_join(thread, (void**) &res) != 0) {
        printf("Error joining thread\n");
        return 2;
    };

    printf("Result: %d\n", *res);
    free(res);
    return 0;
}