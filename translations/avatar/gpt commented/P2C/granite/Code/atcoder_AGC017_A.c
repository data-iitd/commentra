
#include <stdio.h>
#include <math.h>

// Function to calculate combinations C(N, K)
double combi(int N, int K) {
    double a = 1;
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

    int lis[N];
    // Read a list of integers from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &lis[i]);
    }

    int ls[N];
    // Create a list to hold the parity (0 or 1) of each number
    for (int i = 0; i < N; i++) {
        // Append the remainder when divided by 2 (0 for even, 1 for odd)
        ls[i] = lis[i] % 2;
    }

    int one = 0;
    int zero = 0;
    // Count the number of 1s (odd numbers) and 0s (even numbers) in the list
    for (int i = 0; i < N; i++) {
        if (ls[i] == 1) {
            one++;
        } else {
            zero++;
        }
    }

    double pattern_a = 0;
    double pattern_b = 0;
    // Calculate the total number of patterns for the even numbers
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

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
    printf("%.0f\n", pattern_a * pattern_b);

    return 0;
}
