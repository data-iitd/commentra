#include <stdio.h>

// Function to calculate the number of combinations of choosing K items from a set of N items
long long combi(int N, int K) {
    long long a = 1;
    
    for (int i = 0; i < K; i++) {
        a *= (N - i);
        a /= (i + 1);
    }
    
    return a;
}

int main() {
    // Read the input values N and P from the user
    int N, P;
    scanf("%d %d", &N, &P);
    
    // Initialize the answer variable to 0
    long long ans = 0;
    
    // Read the input values from the user and store them in an array
    int lis[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lis[i]);
    }
    
    // Initialize variables to count the number of 1's and 0's
    int one = 0, zero = 0;
    
    // Calculate the number of 1's and 0's in the list
    for (int i = 0; i < N; i++) {
        if (lis[i] % 2 == 1) {
            one++;
        } else {
            zero++;
        }
    }
    
    // Initialize two variables to store the pattern values
    long long pattern_a = 0;
    long long pattern_b = 0;
    
    // Calculate the value of pattern_b by summing up the combinations of choosing 0's from the list
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }
    
    // Calculate the value of pattern_a by summing up the combinations of choosing numbers from the list based on the value of P
    for (int time = 0; time <= one; time++) {
        // Check if the current index (time) is a multiple of P
        if (time % P == 0) {
            // If yes, add the combination value to pattern_a
            pattern_a += combi(one, time);
        }
    }
    
    // Print the final answer as an integer
    printf("%lld\n", pattern_a * pattern_b);
    
    return 0;
}

// <END-OF-CODE>
