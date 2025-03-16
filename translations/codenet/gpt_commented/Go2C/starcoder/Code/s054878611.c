

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// solution function takes an integer n and a pointer to an array of integers a.
// It calculates the maximum frequency of any number or its two consecutive successors in the array.
int solution(int n, int* a) {
        // Create a memoization array to count occurrences of numbers and their successors.
        int* memo = (int*)malloc(sizeof(int) * (1e5 + 2));
        memset(memo, 0, sizeof(int) * (1e5 + 2));
        
        // Iterate through each number in the input array.
        for (int i = 0; i < n; i++) {
                // Increment the count for the current number and its two successors.
                memo[a[i]]++;
                memo[a[i] + 1]++;
                memo[a[i] + 2]++;
        }
        
        // Initialize the output variable to track the maximum frequency found.
        int out = 0
        
        // Iterate through the memoization array to find the maximum frequency.
        for (int i = 0; i < (1e5 + 2); i++) {
                // Update the output if the current count is greater than the current maximum.
                if (memo[i] > 0) {
                        out = max(out, memo[i]);
                }
        }
        
        // Return the maximum frequency found.
        return out;
}

// max function returns the greater of two integers x and y.
int max(int x, int y) {
        if (x > y) {
                return x;
        }
        return y;
}

// main function is the entry point of the program.
int main(void) {
        // Declare a variable to hold the number of elements.
        int n;
        
        // Read the number of elements from standard input.
        scanf("%d", &n);
        
        // Create a pointer to an array to hold the input integers.
        int* a = (int*)malloc(sizeof(int) * n);
        
        // Read each integer into the array.
        for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
        }
        
        // Call the solution function and print the result.
        printf("%d\n", solution(n, a));
        
        // Free the memory allocated to the array.
        free(a);
        
        return 0;
}

