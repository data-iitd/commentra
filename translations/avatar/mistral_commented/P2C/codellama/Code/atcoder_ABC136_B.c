#include <stdio.h>

// Function to find the number of digits in a given number
int main() {
    // Read the number of test cases from the standard input
    int N;
    scanf("%d", &N);

    // Initialize variables
    int i = 1;
    int ans = 0;

    // Calculate the answer using a while loop
    while (10 ** i <= N) {
        // Add the difference between the current power of 10 and the previous power of 10 to the answer
        ans += (10 ** i - 10 ** (i - 1));
        // Increment the index i by 2
        i += 2;
    }

    // Add the remaining digits of the number N to the answer
    ans += max(0, N - 10 ** (i - 1) + 1);

    // Print the answer
    printf("%d\n", ans);

    // End of code
    return 0;
}


Translate the above C code to Java and end with comment "