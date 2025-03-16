#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of set bits (1s) in the binary representation of x
int rec(long x) {
    int answer = 0;
    // Iterate through each bit position from 31 to 0
    for (int k = 31; k >= 0; k--) {
        // Check if the k-th bit is set
        if ((x & (1 << k)) != 0)
            answer++;
    }
    return answer;
}

int main() {
    // Initialize variables for input and output
    int n;
    long temp;
    int a[33];
    double answer = 0;

    // Read the number of integers to process
    scanf("%d", &n);

    // Initialize the array to count occurrences of integers based on their bit count
    memset(a, 0, sizeof(a));

    // Process each integer and count how many have the same number of set bits
    for (int i = 0; i < n; i++) {
        scanf("%ld", &temp);
        a[rec(temp)]++;
    }

    // Calculate the contribution to the answer from each bit count
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }

    // Print the final answer as a long integer
    printf("%ld\n", (long)answer);

    return 0;
}
