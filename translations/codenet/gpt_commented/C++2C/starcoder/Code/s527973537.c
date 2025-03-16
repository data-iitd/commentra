#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input number as a string
    char N[1000]; 
    scanf("%s", N);

    // Initialize a variable to hold the sum of the digits
    int S = 0;

    // Calculate the sum of the digits in the input string
    for (int i = 0; i < strlen(N); i++) {
        S += N[i] - '0'; // Convert character to integer and add to sum
    }

    // Check if the original number is divisible by the sum of its digits
    if (atoi(N) % S == 0) 
        printf("Yes\n"); // Output "Yes" if divisible
    else 
        printf("No\n"); // Output "No" if not divisible

    return 0; // End of the program
}
