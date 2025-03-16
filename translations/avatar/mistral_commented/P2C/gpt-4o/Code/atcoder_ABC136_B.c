#include <stdio.h>
#include <math.h>

int main() {
    // Read the number of test cases from the standard input
    long long N;
    scanf("%lld", &N);

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
    ans += (N - pow(10, i - 1) + 1 > 0) ? (N - pow(10, i - 1) + 1) : 0;

    // Print the answer
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
