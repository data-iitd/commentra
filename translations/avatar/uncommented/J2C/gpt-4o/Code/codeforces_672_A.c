#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* generateString() {
    char* sb = (char*)malloc(4000 * sizeof(char)); // Allocate enough space
    int index = 0;
    for (int i = 1; i <= 1000; i++) {
        index += sprintf(sb + index, "%d", i); // Append the number to the string
    }
    return sb; // Return the dynamically allocated string
}

int main() {
    int n;
    scanf("%d", &n);
    char* generatedString = generateString();
    printf("%c\n", generatedString[n - 1]); // Print the character at position n-1
    free(generatedString); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
