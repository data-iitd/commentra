#include <stdio.h>

// Function to calculate combinations C(N, K)
long long combi(int N, int K) {
    long long a = 1;
    // Calculate the numerator of the combination formula
    for (int i = 0; i < K; i++) {
        a *= N - i;
    }
    // Calculate the denominator of the combination formula
    for (int j = 0; j < K; j++) {
        a /= j + 1;
    }
    return a;
}

int main() {
    int N, P;
    // Read two integers N and P from input
    scanf("%d %d", &N, &P);

    // Initialize the answer variable
    long long ans = 0;

    // Read a list of integers from input
    int lis[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lis[i]);
    }

    // Create a list to hold the parity (0 or 1) of each number
    int ls[N];
    int one = 0, zero = 0;

    for (int i = 0; i < N; i++) {
        // Append the remainder when divided by 2 (0 for even, 1 for odd)
        ls[i] = lis[i] % 2;
        if (ls[i] == 1) {
            one++;
        } else {
            zero++;
        }
    }

    // Initialize variables to count patterns
    long long pattern_a = 0;
    long long pattern_b = 0;

    // Calculate the total number of patterns for the even numbers
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

    // Initialize a variable to track the number of odd numbers used
    int time = 0;

    // Loop through all possible counts of odd numbers used
    while (time <= one) {
        // Check if the current count of odd numbers is congruent to P modulo 2
        if (time % 2 == P) {
            // If it is, add the number of combinations to pattern_a
            pattern_a += combi(one, time);
        }
        time++;
    }

    // Print the final result, which is the product of pattern_a and pattern_b
    printf("%lld\n", pattern_a * pattern_b);

    return 0;
}

// <END-OF-CODE>
