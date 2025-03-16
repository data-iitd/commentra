#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* TenToN(int number, int n) {
    char* s = (char*)malloc(1000000 * sizeof(char)); // Allocate memory for the result string
    int index = 0;
    int tmp = number; // Initialize temporary variable

    // Repeat the following process until the number becomes less than N
    while (1) {
        // Append the remainder of the division by N to the result string
        char remainder[10];
        sprintf(remainder, "%d", tmp % n);
        strcat(remainder, s);
        s = remainder;

        // If the number is less than N, break the loop
        if (tmp < n) {
            break;
        }

        // Divide the number by N
        tmp /= n;
    }

    // Return the result string
    return s;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // Calculate the base-10 representation of N up to digit count K
    char* s = TenToN(N, K);

    // Print the length of the calculated string
    printf("%lu\n", strlen(s));

    // Free the allocated memory
    free(s);

    return 0;
}
