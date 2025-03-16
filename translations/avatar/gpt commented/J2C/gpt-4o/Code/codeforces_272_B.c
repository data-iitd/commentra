#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 33

// Function to count the number of set bits in the binary representation of x
int countSetBits(long x) {
    int count = 0;
    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k)) != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    // Read the number of integers to process
    int n;
    scanf("%d", &n);

    // Array to count occurrences of integers based on their bit count
    int a[MAX_BITS] = {0};

    // Process each integer and count how many have the same number of set bits
    for (int i = 0; i < n; i++) {
        long x;
        scanf("%ld", &x);
        a[countSetBits(x)]++;
    }

    // Variable to accumulate the final answer
    double answer = 0;

    // Calculate the contribution to the answer from each bit count
    for (int i = 0; i < MAX_BITS; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }

    // Print the final answer as a long integer
    printf("%ld\n", (long)answer);

    return 0;
}

// <END-OF-CODE>
