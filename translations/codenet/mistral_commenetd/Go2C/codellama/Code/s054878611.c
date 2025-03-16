
#include <stdio.h>

// Function to find the maximum number of occurrences of a number in the array
int solution(int n, int a[]) {
        // Initialize a memo table to store the number of occurrences of each number
        int memo[100002];

        // Iterate through the array and update the memo table
        for (int i = 0; i < n; i++) {
                // Increment the memo table for the current number and the next two numbers
                memo[a[i]]++;
                memo[a[i]+1]++;
                memo[a[i]+2]++;
        }

        // Initialize output variable to store the maximum number of occurrences found
        int out = 0;

        // Iterate through the memo table and update the output variable if a larger number is found
        for (int i = 0; i < 100002; i++) {
                if (memo[i] > 0) {
                        // Update the output variable with the maximum number found so far
                        out = max(out, memo[i]);
                }
        }

        // Return the maximum number of occurrences found
        return out;
}

// Function to find the maximum of two numbers
int max(int x, int y) {
        // Return the larger number between x and y
        if (x > y) {
                return x;
        }
        return y;
}

// Main function to read input and call the solution function
int main() {
        // Read the size of the array from the standard input
        int n;
        scanf("%d", &n);

        // Allocate memory for the array and read its elements from the standard input
        int a[n];
        for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
        }

        // Call the solution function and print the result
        printf("%d\n", solution(n, a));

        // End of code
        return 0;
}