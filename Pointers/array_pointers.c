#include <stdio.h>

int main() {
    int my_arr[4] = {1, 2, 3, 4};
    printf("%d, %d, %d, %d\n", my_arr[0], my_arr[1], my_arr[2], my_arr[3]);
    // 1, 2, 3, 4
    int *i;

    i = my_arr;
    *i = 10; // change first element
    i+=1; // move to next element
    *i = 20; // change second element
    printf("%d, %d, %d, %d\n", my_arr[0], my_arr[1], my_arr[2], my_arr[3]);
    // 10, 20, 3, 4

    return 0;
}