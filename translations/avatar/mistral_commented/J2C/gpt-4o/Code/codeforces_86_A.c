#include <stdio.h>  // Including standard input-output header
#include <math.h>   // Including math header for mathematical functions

// Function to calculate the number of digits in a number
int power(long a) {
    int res = 0;  // Initializing the result variable to 0
    while (a > 0) {  // While the number 'a' is greater than 0
        res++;  // Increment the result variable
        a = a / 10;  // Divide the number by 10 to get the number of digits
    }
    return res;  // Return the result
}

// Function to calculate the product of a number with the maximum number that can be formed using its digits
long mult(long a) {
    int pow = power(a);  // Calculate the power of the number 'a'
    long max = 0;  // Initializing the maximum variable to 0
    for (int j = 0; j < pow; ++j) {
        // Loop to calculate the maximum number that can be formed using the digits of the number 'a'
        max = max * 10 + 9;  // Multiply the maximum variable with 10 and add 9 to get the next digit
    }
    return a * (max - a);  // Return the product of the number 'a' and the maximum number calculated above
}

int main() {
    long l, r;  // Declaring variables for input numbers
    long res = 0;  // Initializing the result variable to 0
    long maxxes[10];  // Array to store the maximum numbers that can be formed using each digit
    long temp = 0;  // Initializing a temporary variable to 0

    // Loop to calculate and store the maximum numbers that can be formed using each digit
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;  // Multiply the temporary variable with 10 and add 9 to get the next digit
        maxxes[i] = (temp / 2) * (temp - temp / 2);  // Calculate and store the maximum number in the 'i'th index of the 'maxxes' array
    }

    // Read the first and second numbers from the console
    scanf("%ld %ld", &l, &r);

    // Calculate the product of the first number 'l' and the second number 'r' with the maximum number that can be formed using their digits
    res = fmax(mult(l), res);  // Calculate the product of the first number 'l'
    res = fmax(mult(r), res);  // Calculate the product of the second number 'r'

    temp = 0;  // Resetting the temporary variable to 0

    // Loop to check if the range between the first and second number includes the maximum number that can be formed using the 'i'th digit
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;  // Multiply the temporary variable with 10 and add 9 to get the next digit
        if (l <= temp / 2 && temp / 2 <= r)  // Check if the range includes the maximum number that can be formed using the 'i'th digit
            res = fmax(maxxes[i], res);  // Update the result variable with the maximum number that can be formed using the 'i'th digit if the condition is true
    }

    printf("%ld\n", res);  // Printing the final result
    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
