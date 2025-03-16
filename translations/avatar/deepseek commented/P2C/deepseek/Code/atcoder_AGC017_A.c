#include <stdio.h>
#include <stdlib.h>

// Function to calculate the binomial coefficient
double combi(int N, int K) {
    double a = 1.0;
    // Calculate the product part of the binomial coefficient
    for (int i = 0; i < K; i++) {
        a *= (double)(N - i);
    }
    // Calculate the division part of the binomial coefficient
    for (int j = 1; j <= K; j++) {
        a /= (double)j;
    }
    return a;
}

int main() {
    int N, P;
    // Read the values of N and P from input
    scanf("%d %d", &N, &P);

    int lis[N];
    // Read a list of integers from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &lis[i]);
    }

    int ls[N];
    // Create a new list where each element is the remainder when divided by 2
    for (int i = 0; i < N; i++) {
        ls[i] = lis[i] % 2;
    }

    // Count the number of 1s and 0s in the list
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++) {
        if (ls[i] == 1) {
            one++;
        } else {
            zero++;
        }
    }

    // Initialize variables to store the number of patterns
    double pattern_a = 0.0, pattern_b = 0.0;

    // Calculate the number of patterns with `j` zeros using the combi function
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

    // Initialize time to 0 for the while loop
    int time = 0;

    // Calculate the number of patterns with `time` ones, considering the parity with P
    while (time <= one) {
        if (time % 2 == P) {
            pattern_a += combi(one, time);
        }
        time++;
    }

    // Print the result as an integer by multiplying pattern_a and pattern_b
    printf("%d\n", (int)(pattern_a * pattern_b));

    return 0;
}
