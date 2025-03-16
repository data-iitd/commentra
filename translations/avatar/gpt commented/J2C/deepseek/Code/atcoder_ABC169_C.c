#include <stdio.h>
#include <string.h>

int main() {
    long a;
    char b[100];
    char bStr[100];
    int length, i;
    int bInt;
    long result;

    // Read a long integer value from the user
    scanf("%ld", &a);

    // Read a string value from the user
    scanf("%s", b);

    // Initialize an empty string to build the integer representation
    strcpy(bStr, "");

    // Get the length of the character array
    length = strlen(b);

    // Loop through each character in the character array
    for (i = 0; i < length; i++) {
        // If the character is not a '.', append it to bStr
        if (b[i] != '.') {
            strncat(bStr, &b[i], 1);
        }
    }

    // Convert the built string (bStr) to an integer
    bInt = atoi(bStr);

    // Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
    result = (a * bInt) / 100;

    // Print the result to the console
    printf("%ld\n", result);

    return 0;
}
