

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Main function starts here
int main() {
    // Declare and initialize variables
    char N[100]; // array to store the input number
    int S = 0; // sum of digits of the number
    int i; // loop variable

    // Read the input number from the standard input
    printf("Enter a number: ");
    scanf("%s", N);

    // Calculate the sum of digits of the number
    for (i = 0; N[i]!= '\0'; i++) {
        // Increment the sum by the ASCII value of the current digit
        // (subtracting the ASCII value of '0' to get the actual digit value)
        S += N[i] - '0';
    }

    // Check if the number is divisible by the sum of its digits
    if (atoi(N) % S == 0) { // Convert the string to an integer using atoi()
        printf("Yes\n"); // Output "Yes" if the number is divisible
    } else {
        printf("No\n"); // Output "No" otherwise
    }

    // Terminate the program with an exit status of 0
    return 0;
}

