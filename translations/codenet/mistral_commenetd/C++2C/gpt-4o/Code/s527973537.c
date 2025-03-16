#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare and initialize variables
    char N[100]; // array to store the input number
    int S = 0; // sum of digits of the number

    // Read the input number from the standard input
    printf("Enter a number: ");
    scanf("%s", N);

    // Calculate the sum of digits of the number
    for (int i = 0; i < strlen(N); i++) {
        // Increment the sum by the actual digit value
        S += N[i] - '0';
    }

    // Convert the string to an integer using atoi()
    int num = atoi(N);

    // Check if the number is divisible by the sum of its digits
    if (num % S == 0) {
        printf("Yes\n"); // Output "Yes" if the number is divisible
    } else {
        printf("No\n"); // Output "No" otherwise
    }

    // Terminate the program with an exit status of 0
    return 0;
}

// <END-OF-CODE>
