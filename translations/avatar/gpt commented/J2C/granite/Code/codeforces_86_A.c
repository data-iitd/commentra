
#include <stdio.h>
#include <math.h>

// Method to calculate the number of digits in a given number
int power(long a) {
    int res = 0;
    // Count the number of digits by dividing the number by 10 until it becomes 0
    while (a > 0) {
        res++;
        a = a / 10;
    }
    return res;
}

// Method to calculate the product of a number and the difference between the largest number with the same number of digits and the number itself
long mult(long a) {
    int pow = power(a); // Get the number of digits in 'a'
    long max = 0;
    // Create the largest number with the same number of digits as 'a' (all 9s)
    for (int j = 0; j < pow; ++j) {
        max = max * 10 + 9;
    }
    // Return the product of 'a' and the difference between the largest number and 'a'
    return a * (max - a);
}

int main() {
    long l, r, res = 0; // Variable to store the maximum result
    long maxxes[10]; // Array to store maximum products for numbers with different digit lengths
    long temp = 0;

    // Precompute maximum products for numbers with up to 10 digits
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9; // Create the largest number with i+1 digits (all 9s)
        maxxes[i] = temp / 2 * (temp - temp / 2); // Calculate the maximum product for this digit length
    }

    // Read the lower bound of the range
    scanf("%ld", &l);
    // Read the upper bound of the range
    scanf("%ld", &r);

    // Calculate the maximum product for the lower bound 'l'
    res = fmax(mult(l), res);
    // Calculate the maximum product for the upper bound 'r'
    res = fmax(mult(r), res);
    temp = 0;

    // Check for numbers formed by all 9s and see if they lie within the range [l, r]
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9; // Create the largest number with i+1 digits (all 9s)
        // If the half of this number is within the range, consider its maximum product
        if (l <= temp / 2 && temp / 2 <= r)
            res = fmax(maxxes[i], res);
    }

    // Output the maximum product found
    printf("%ld\n", res);

    return 0;
}
