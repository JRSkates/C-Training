#include <stdio.h>

void counter_function() {
    static int counter = 0; // Static variable to retain its value between function calls
    counter++;
    printf("Counter: %d\n", counter);
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        counter_function(); // Call the function within the loop
    }

    return 0;
}
