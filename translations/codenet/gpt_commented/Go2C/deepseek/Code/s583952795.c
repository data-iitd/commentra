#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert a number from base 10 to base N
char* TenToN(int number, int n) {
    char* s = (char*)malloc(100000 * sizeof(char)); // Allocate memory for the result string
    int tmp = number; // Temporary variable to hold the current number
    int index = 0; // Index for the result string
    while (1) {
        // Prepend the remainder of the division to the result string
        char remainder[10];
        sprintf(remainder, "%d", tmp % n);
        strcat(remainder, s);
        s = remainder;
        if (tmp < n) { // If the temporary number is less than the base, exit the loop
            break;
        }
        tmp /= n; // Divide the temporary number by the base
    }
    return s; // Return the converted string
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    // Convert the number N from base 10 to base K
    char* s = TenToN(N, K);
    // Print the length of the resulting string
    printf("%lu\n", strlen(s));
    free(s); // Free the allocated memory
    return 0;
}
