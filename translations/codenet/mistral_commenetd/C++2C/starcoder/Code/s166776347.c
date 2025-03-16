#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <float.h>

// Macro for for loop
#define FOR(i,a,b) for (int i=(a);i<(b);++i)

// Main function
int main() {
    // Input
    int N, K; // Number of elements in array A and the value of K
    scanf("%d %d", &N, &K);
    int A[N]; // Array to store input elements
    FOR(i,0,N) scanf("%d", &A[i]); // Read elements of array A from standard input

    // Solution
    int ans1 = 0; // Initialize answer for the first part
    FOR(i,0,N){ // Iterate through all elements in array A
        FOR(j,0,N){ // Iterate through all other elements in array A
            if (i >= j) continue; // Skip if current index is greater than or equal to the index of the inner loop
            if (A[i] > A[j]) ans1++; // Increment answer if the current element is greater than the inner element
        }
    }

    int count[2005] = {0}; // Initialize an array to store the count of each unique element in array A
    FOR(i,0,N){ // Iterate through all elements in array A
        count[A[i]-1]++; // Increment the count of the current element in the count array
    }

    int ans2 = 0; // Initialize answer for the second part
    int remain = N; // Initialize the remaining number of elements to be paired
    FOR(i,0,2005){ // Iterate through all unique elements in array A
        remain -= count[i]; // Decrement the remaining number of elements to be paired for the current unique element
        ans2 += count[i]*remain; // Calculate the contribution of the current unique element to the answer
    }

    int ans = 0; // Initialize the final answer
    int tmp = K*(K-1); // Calculate (K*(K-1)) modulo 1e9+7
    tmp /= 2; // Divide by 2 to get the number of unique pairs that can be formed using K elements
    tmp *= ans2; // Multiply the temporary variable with the answer for the second part
    ans += ans1 * K; // Add the answer for the first part multiplied by K to the final answer
    ans += tmp; // Add the temporary variable to the final answer

    // Output
    printf("%d\n", ans); // Print the final answer
}

