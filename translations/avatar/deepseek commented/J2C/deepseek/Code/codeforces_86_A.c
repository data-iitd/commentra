#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of digits in a given long integer
int power(long a) {
    int res = 0;
    while (a > 0) {
        res++;
        a = a / 10;
    }
    return res;
}

// Function to calculate the maximum product of two numbers formed by splitting the given number into two parts
long mult(long a) {
    int pow = power(a);
    long max = 0;
    for (int j = 0; j < pow; ++j) {
        max = max * 10 + 9;
    }
    return a * (max - a);
}

int main() {
    // Read two long integers from the input
    long l, r;
    scanf("%ld %ld", &l, &r);
    long res = 0;
    long maxxes[10];
    long temp = 0;

    // Calculate the maximum product for each range and store it in the array maxxes
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        maxxes[i] = temp / 2 * (temp - temp / 2);
    }

    // Calculate the maximum product for the given ranges and update the result res
    res = (mult(l) > res) ? mult(l) : res;
    res = (mult(r) > res) ? mult(r) : res;
    temp = 0;

    // Check if the middle value of the range is within the given range and update the result res accordingly
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        if (l <= temp / 2 && temp / 2 <= r) {
            res = (maxxes[i] > res) ? maxxes[i] : res;
        }
    }

    // Print the final result
    printf("%ld\n", res);
    return 0;
}

