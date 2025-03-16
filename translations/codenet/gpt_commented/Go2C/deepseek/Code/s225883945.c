#include <stdio.h>
#include <stdlib.h>

// Function to read the next line of input as an integer
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read 'n' integers from input and return them as a pointer to an array of integers
int* nextInts(int n) {
    int* slice = (int*)malloc(n * sizeof(int)); // Allocate memory for 'n' integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &slice[i]); // Fill the array with integers from input
    }
    return slice; // Return the pointer to the array of integers
}

int main() {
    // Read two integers from input: n (number of elements) and k (some parameter)
    int n = nextInt();
    int k = nextInt();
    
    // Read 'n' integers into array 'a'
    int* a = nextInts(n);
    
    // Initialize sum with the value of k and set ans to 1
    int sum = k;
    int ans = 1;
    
    // Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
    while (sum < n) {
        sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
        ans++; // Increment the answer counter
    }
    
    // Print the final answer
    printf("%d\n", ans);
    
    // Free the allocated memory for the array 'a'
    free(a);
    
    return 0;
}
