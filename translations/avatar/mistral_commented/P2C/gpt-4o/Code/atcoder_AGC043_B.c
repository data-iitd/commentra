#include <stdio.h>

// Define a helper function 'twos_in_factorial' to count the number of twos in the factorial of a given number
int twos_in_factorial(int n) {
    // Calculate the number of twos in the factorial of 'n'
    return n - __builtin_popcount(n); // Using GCC built-in function to count '1' bits
}

// Define a helper function 'parity_of_nCr' to check if the index 'i' has odd parity in the combination 'nCr'
int parity_of_nCr(int n, int i) {
    // Use the 'twos_in_factorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
    int f_n = twos_in_factorial(n);
    int f_n_i = twos_in_factorial(n - i);
    int f_i = twos_in_factorial(i);
    // Return 1 (true) if the difference is greater than zero
    return (f_n - f_n_i - f_i) > 0;
}

int main() {
    // Read the input values
    int n;
    scanf("%d", &n);
    
    int nums[100]; // Assuming a maximum size of 100 for the input array
    for (int j = 0; j < n; j++) {
        scanf("%d", &nums[j]);
        nums[j]--; // Decrement each number by 1
    }
    
    // Initialize a flag to indicate if there is no '1' in the list of numbers
    int no_one = 0;
    
    // If there is no '1' in the list of numbers, then replace each number by half of it
    int found_one = 0;
    for (int j = 0; j < n; j++) {
        if (nums[j] == 0) {
            found_one = 1;
            break;
        }
    }
    
    if (!found_one) {
        for (int j = 0; j < n; j++) {
            nums[j] /= 2; // Replace each number by half of it
        }
        no_one = 1;
    }
    
    // Initialize a flag to indicate if the result is odd
    int is_odd = 0;
    
    // Iterate through each number in the list and check if it satisfies the given condition
    for (int i = 0; i < n; i++) {
        // Skip the number if it doesn't satisfy the parity condition
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            // Toggle the 'is_odd' flag
            is_odd ^= 1;
        }
    }
    
    // Print the result based on the value of the 'is_odd' flag
    if (!is_odd) {
        printf("0\n");
    } else {
        // If there is no '1' in the list of numbers, then print the result with the 'no_one' flag shifted to the left
        printf("%d\n", 1 << no_one);
    }
    
    return 0;
}

// <END-OF-CODE>
