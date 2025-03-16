#include <stdio.h>

// solution function takes an integer n and an array of integers a.
// It calculates the maximum frequency of any number or its two consecutive successors in the array.
int solution(int n, int a[]) {
    // Create a memoization array to count occurrences of numbers and their successors.
    int memo[100002] = {0};
    
    // Iterate through each number in the input array.
    for (int i = 0; i < n; i++) {
        // Increment the count for the current number and its two successors.
        memo[a[i]]++;
        memo[a[i] + 1]++;
        memo[a[i] + 2]++;
    }
    
    // Initialize the output variable to track the maximum frequency found.
    int out = 0;
    
    // Iterate through the memoization array to find the maximum frequency.
    for (int i = 0; i < 100002; i++) {
        // Update the output if the current count is greater than the current maximum.
        if (memo[i] > 0) {
            out = (out > memo[i]) ? out : memo[i];
        }
    }
    
    // Return the maximum frequency found.
    return out;
}

// main function is the entry point of the program.
int main() {
    // Declare a variable to hold the number of elements.
    int n;
    
    // Read the number of elements from standard input.
    scanf("%d", &n);
    
    // Create an array to hold the input integers.
    int a[n];
    
    // Read each integer into the array.
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Call the solution function and print the result.
    printf("%d\n", solution(n, a));
    
    return 0;
}
