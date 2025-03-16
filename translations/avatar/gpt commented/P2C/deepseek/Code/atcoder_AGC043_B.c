#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of factors of 2 in n!
int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    return n - (int)__builtin_popcount(n);
}

// Function to determine the parity (even or odd) of the binomial coefficient C(n, i)
int parity_of_nCr(int n, int i) {
    // Reference to the function that calculates the number of factors of 2
    int f = twos_in_factorial(n) - twos_in_factorial(n - i) - twos_in_factorial(i);
    // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return f > 0;
}

int main() {
    // Read an integer n from input
    int n;
    scanf("%d", &n);
    
    // Read a list of integers, subtracting 1 from each input value
    int nums_size;
    scanf("%d", &nums_size);
    int nums[nums_size];
    for (int i = 0; i < nums_size; i++) {
        scanf("%d", &nums[i]);
        nums[i]--;
    }
    
    int no_one = 0;  // Flag to check if there are no '1's in the input list
    int found_one = 0;
    for (int i = 0; i < nums_size; i++) {
        if (nums[i] == 0) {
            found_one = 1;
            break;
        }
    }
    if (!found_one) {
        // If there are no '1's, divide each number in nums by 2
        for (int i = 0; i < nums_size; i++) {
            nums[i] /= 2;
        }
        no_one = 1;  // Set the flag to True since there were no '1's
    }

    int is_odd = 0;  // Flag to track if the overall parity is odd
    for (int i = 0; i < nums_size; i++) {
        // Check the parity of C(n-1, i) and if num is odd
        if (!parity_of_nCr(n - 1, i) && nums[i] & 1) {
            is_odd ^= 1;  // Toggle the is_odd flag if the conditions are met
        }
    }

    // Print the result based on the parity
    if (!is_odd) {
        printf("0\n");  // If the overall parity is even, print 0
    } else {
        printf("%d\n", 1 << no_one);  // If odd, print 1 or 2 based on the no_one flag
    }

    return 0;
}
