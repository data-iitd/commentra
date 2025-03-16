#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[1000]; // Declare a character array to store the input string
    char b[1000]; // Declare a character array to store the modified string
    int i, j = 0; // Declare integer variables to use as indices

    // Read the input string from the console and store it in the 'a' array
    fgets(a, sizeof(a), stdin);

    // Replace all occurrences of ',' in the 'a' string with a single space and store the result in the 'b' array
    for (i = 0; a[i] != '\0'; i++) {
        if (a[i] == ',') {
            b[j++] = ' ';
        } else {
            b[j++] = a[i];
        }
    }
    b[j] = '\0'; // Add the null terminator to the end of the 'b' array

    // Print the modified string stored in the 'b' array to the console
    printf("%s", b);

    return 0;
}
