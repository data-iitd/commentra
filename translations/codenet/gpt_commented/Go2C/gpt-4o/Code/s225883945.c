#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from input
int nextInt() {
    int value;
    scanf("%d", &value); // Read an integer from standard input
    return value; // Return the integer value
}

// Function to read 'n' integers from input and return them in an array
int* nextInts(int n) {
    int* array = (int*)malloc(n * sizeof(int)); // Allocate memory for 'n' integers
    for (int i = 0; i < n; i++) {
        array[i] = nextInt(); // Fill the array with integers from input
    }
    return array; // Return the array of integers
}

int main() {
    // Read two integers from input: n (number of elements) and k (some parameter)
    int n = nextInt();
    int k = nextInt();
    
    // Read 'n' integers into array 'a'
    int* a = nextInts(n);
    
    // Avoid unused variable error by assigning a value to the first element of 'a'
    a[0] = 0;

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
    
    // Free the allocated memory
    free(a);
    
    return 0; // Return success
}

// <END-OF-CODE>
