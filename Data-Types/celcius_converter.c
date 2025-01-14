#include <stdio.h>

// Function to convert celcius to fahrenheit and kelvin
void celcius_converter(int celcius) {
    float fahrenheit = (celcius * 9/5) + 32;
    float kelvin = celcius + 273.15;

    printf("Temperature in Celsius: %d\n", celcius);
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    printf("Temperature in Kelvin: %.2f\n", kelvin);
}

int main() {
    float temperature = 21.0;
    celcius_converter(temperature);

    return 0;
}

// gcc -o celcius_converter celcius_converter.c
// ./celcius_converter 