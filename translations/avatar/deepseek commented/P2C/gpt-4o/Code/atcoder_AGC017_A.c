#include <stdio.h>

long long combi(int N, int K) {
    long long a = 1;
    // Calculate the product part of the binomial coefficient
    for (int i = 0; i < K; i++) {
        a *= (N - i);
    }
    // Calculate the division part of the binomial coefficient
    for (int j = 1; j <= K; j++) {
        a /= j;
    }
    return a;
}

int main() {
    int N, P;
    // Read the values of N and P from input
    scanf("%d %d", &N, &P);

    long long pattern_a = 0;
    long long pattern_b = 0;

    // Read a list of integers from input
    int lis[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lis[i]);
    }

    // Create a new list where each element is the remainder when divided by 2
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++) {
        if (lis[i] % 2 == 1) {
            one++;
        } else {
            zero++;
        }
    }

    // Calculate the number of patterns with `j` zeros using the combi function
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

    // Initialize time to 0 for the while loop
    for (int time = 0; time <= one; time++) {
        if (time % 2 == P) {
            pattern_a += combi(one, time);
        }
    }

    // Print the result as an integer by multiplying pattern_a and pattern_b
    printf("%lld\n", pattern_a * pattern_b);

    return 0;
}

// <END-OF-CODE>
