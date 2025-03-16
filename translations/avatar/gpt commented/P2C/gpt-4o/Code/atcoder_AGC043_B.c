#include <stdio.h>

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    int count = 0;
    while (n > 0) {
        count += n & 1; // Count the number of 1s in the binary representation
        n >>= 1; // Right shift n by 1
    }
    return n - count; // Return the difference
}

int parity_of_nCr(int n, int i) {
    // Determine the parity (even or odd) of the binomial coefficient C(n, i)
    int f_n = twos_in_factorial(n);
    int f_n_i = twos_in_factorial(n - i);
    int f_i = twos_in_factorial(i);
    // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return (f_n - f_n_i - f_i) > 0;
}

int main() {
    int n;
    scanf("%d", &n); // Read an integer n from input

    int nums[100]; // Assuming a maximum of 100 inputs
    int count = 0;
    char ch;
    while (scanf("%d%c", &nums[count], &ch) == 2) {
        nums[count]--; // Subtracting 1 from each input value
        count++;
        if (ch == '\n') break; // Break on newline
    }

    int no_one = 0; // Flag to check if there are no '1's in the input list
    for (int j = 0; j < count; j++) {
        if (nums[j] == 0) {
            no_one = 1; // Set the flag to 1 if there is a '1'
            break;
        }
    }

    if (no_one == 0) {
        // If there are no '1's, divide each number in nums by 2
        for (int j = 0; j < count; j++) {
            nums[j] /= 2;
        }
    }

    int is_odd = 0; // Flag to track if the overall parity is odd
    for (int i = 0; i < count; i++) {
        // Check the parity of C(n-1, i) and if num is odd
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            is_odd ^= 1; // Toggle the is_odd flag if the conditions are met
        }
    }

    // Print the result based on the parity
    if (!is_odd) {
        printf("0\n"); // If the overall parity is even, print 0
    } else {
        printf("%d\n", 1 << no_one); // If odd, print 1 or 2 based on the no_one flag
    }

    return 0;
}

// <END-OF-CODE>
