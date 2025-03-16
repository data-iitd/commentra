#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the modulo constant
#define mod 1000000007

// Helper functions to read different types of input
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

int *II() {
    int *arr = (int *)malloc(sizeof(int) * 2);
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

int *III() {
    int *arr = (int *)malloc(sizeof(int) * 3);
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    return arr;
}

// Function to read N lines of input and return them as a list of tuples
int **Line(int N) {
    int **read_all = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        read_all[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d", &read_all[i][0], &read_all[i][1]);
    }
    return read_all;
}

// Read the string input S
char *S = (char *)malloc(sizeof(char) * 1000001);
scanf("%s", S);
int n = strlen(S);

// Initialize a 2D list for dynamic programming
int **dp = (int **)malloc(sizeof(int *) * n);
for (int i = 0; i < n; i++) {
    dp[i] = (int *)malloc(sizeof(int) * 13);
    memset(dp[i], 0, sizeof(int) * 13);
}

// Fill the dp table based on the characters in S
for (int i = 0; i < n; i++) {
    if (i == 0) {
        // Handle the first character
        if (S[i] != '?') {
            dp[i][S[i] - '0'] += 1;  // Increment the count for the specific digit
        } else {
            // If the character is '?', increment counts for all digits (0-9)
            for (int j = 0; j < 10; j++) {
                dp[i][j] += 1;
            }
        }
    } else {
        // Process subsequent characters
        if (S[i] != '?') {
            // If the character is a specific digit
            for (int k = 0; k < 13; k++) {
                dp[i][(k * 10 + S[i] - '0') % 13] += dp[i - 1][k];
            }
        } else {
            // If the character is '?', consider all digits (0-9)
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                }
            }
        }

        // Apply modulo to keep the values manageable
        for (int k = 0; k < 13; k++) {
            dp[i][k] %= mod;
        }
    }
}

// Output the count of valid numbers that are divisible by 13 and end with digit 5
printf("%d\n", dp[n - 1][5]);

