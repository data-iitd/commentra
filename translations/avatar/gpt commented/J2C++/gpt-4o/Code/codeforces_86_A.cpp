#include <iostream>
#include <algorithm>

using namespace std;

// Method to calculate the number of digits in a given number
int power(long long a) {
    int res = 0;
    // Count the number of digits by dividing the number by 10 until it becomes 0
    while (a > 0) {
        res++;
        a = a / 10;
    }
    return res;
}

// Method to calculate the product of a number and the difference between the largest number with the same number of digits and the number itself
long long mult(long long a) {
    int pow = power(a); // Get the number of digits in 'a'
    long long max = 0;
    // Create the largest number with the same number of digits as 'a' (all 9s)
    for (int j = 0; j < pow; ++j) {
        max = max * 10 + 9;
    }
    // Return the product of 'a' and the difference between the largest number and 'a'
    return a * (max - a);
}

int main() {
    long long l, r;
    cin >> l >> r; // Read the lower and upper bounds of the range
    long long res = 0; // Variable to store the maximum result
    long long maxxes[10]; // Array to store maximum products for numbers with different digit lengths
    long long temp = 0;

    // Precompute maximum products for numbers with up to 10 digits
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9; // Create the largest number with i+1 digits (all 9s)
        maxxes[i] = (temp / 2) * (temp - temp / 2); // Calculate the maximum product for this digit length
    }

    // Calculate the maximum product for the lower bound 'l'
    res = max(mult(l), res);
    // Calculate the maximum product for the upper bound 'r'
    res = max(mult(r), res);
    temp = 0;

    // Check for numbers formed by all 9s and see if they lie within the range [l, r]
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9; // Create the largest number with i+1 digits (all 9s)
        // If the half of this number is within the range, consider its maximum product
        if (l <= temp / 2 && temp / 2 <= r)
            res = max(maxxes[i], res);
    }

    // Output the maximum product found
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
