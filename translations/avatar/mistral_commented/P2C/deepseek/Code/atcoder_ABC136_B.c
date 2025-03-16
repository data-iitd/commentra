#include <stdio.h>
#include <math.h>

// Function to find the number of digits in a given number
void main() {
    // Read the number of test cases from the standard input
    int N;
    scanf("%d", &N);

    // Initialize variables
    int i = 1;
    long long ans = 0;

    // Calculate the answer using a while loop
    while (pow(10, i) <= N) {
        // Add the difference between the current power of 10 and the previous power of 10 to the answer
        ans += (pow(10, i) - pow(10, i - 1));
        // Increment the index i by 2
        i += 2;
    }

    // Add the remaining digits of the number N to the answer
    ans += fmax(0, N - pow(10, i - 1) + 1);

    // Print the answer
    printf("%lld\n", ans);
}
