#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    return n - __builtin_popcount(n);
}

int parity_of_nCr(int n, int i) {
    // Determine the parity (even or odd) of the binomial coefficient C(n, i)
    int f = twos_in_factorial;  // Reference to the function that calculates the number of factors of 2
    // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return f(n) - f(n - i) - f(i) > 0;
}

int main() {
    // Read an integer n from input
    int n;
    scanf("%d", &n);
    // Read a list of integers, subtracting 1 from each input value
    int nums[n];
    char *input = malloc(sizeof(char) * 100);
    fgets(input, 100, stdin);
    char *token = strtok(input, " ");
    for (int i = 0; i < n; i++) {
        nums[i] = atoi(token) - 1;
        token = strtok(NULL, " ");
    }
    free(input);

    int no_one = 0;  // Flag to check if there are no '1's in the input list
    if (1 != nums[0]) {
        // If there are no '1's, divide each number in nums by 2
        for (int i = 0; i < n; i++) {
            nums[i] /= 2;
        }
        no_one = 1;  // Set the flag to True since there were no '1's
    }

    int is_odd = 0;  // Flag to track if the overall parity is odd
    for (int i = 0; i < n; i++) {
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

