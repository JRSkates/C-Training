#include <stdio.h>

void phrase_function(char phrase[]);

int main() {
    // String phrase to pass to function
    char phrase[] = "This is the phrase being passed to the function";

    // Pass the phrase to the function
    phrase_function(phrase);

    return 0;
}
void phrase_function(char phrase[]) {
    // Print the phrase
    printf("%s\n", phrase);
}
