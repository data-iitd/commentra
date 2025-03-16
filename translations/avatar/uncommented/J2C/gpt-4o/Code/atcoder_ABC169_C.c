#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long a;
    char b[100]; // Assuming the input string will not exceed 99 characters
    scanf("%ld", &a);
    scanf("%s", b);

    char bStr[100]; // To store the modified string without '.'
    int j = 0;

    for (int i = 0; i < strlen(b); i++) {
        if (b[i] != '.') {
            bStr[j++] = b[i];
        }
    }
    bStr[j] = '\0'; // Null-terminate the string

    int bInt = atoi(bStr); // Convert the string to an integer
    long result = (a * bInt) / 100; // Calculate the result

    printf("%ld\n", result); // Print the result

    return 0;
}

// <END-OF-CODE>
