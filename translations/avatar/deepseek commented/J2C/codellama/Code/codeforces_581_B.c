#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

#define MAX_SIZE 1000000 

int main() { 
    // Step 1: Declare variables
    int n; 
    long a[MAX_SIZE]; 
    long dp[MAX_SIZE]; 
    int i; 

    // Step 2: Read input values
    scanf("%d", &n); 
    for (i = 0; i < n; i++) { 
        scanf("%ld", &a[i]); 
    } 

    // Step 3: Initialize a dynamic programming array
    for (i = 0; i < n; i++) { 
        dp[i] = -1; 
    } 

    // Step 4: Fill the dynamic programming array
    dp[n - 1] = a[n - 1]; 
    for (i = n - 1; i >= 0; i--) { 
        dp[i] = max(dp[i + 1], a[i]); 
    } 

    // Step 5: Calculate the result
    for (i = 0; i < n; i++) { 
        if (a[i] > dp[i + 1]) { 
            printf("0 "); 
        } else { 
            printf("%ld ", (dp[i + 1] - a[i] + 1)); 
        } 
    } 

    // Step 6: Print the result
    printf("\n"); 

    // Step 7: Debugging (optional)
    // debug(a, dp); 

    // Step 8: End of code
    return 0; 
} 

void debug(long a[], long dp[]) { 
    int i; 
    for (i = 0; i < MAX_SIZE; i++) { 
        printf("%ld ", a[i]); 
    } 
    printf("\n"); 
    for (i = 0; i < MAX_SIZE; i++) { 
        printf("%ld ", dp[i]); 
    } 
    printf("\n"); 
} 

long max(long a, long b) { 
    return a > b ? a : b; 
} 

