#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
<<<<<<< HEAD
#include <stdbool.h>

// Function to calculate the sum of digits
int sum_of_digits(const char *str) {
=======

// Function to calculate the sum of digits in a string
int digit_sum(const char *str) {
>>>>>>> 98c87cb78a (data updated)
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i] - '0';
    }
    return sum;
}

// Main function
int main() {
    char N[100]; // Buffer to hold the input string
    scanf("%s", N); // Read input string

<<<<<<< HEAD
    int digit_sum = sum_of_digits(N); // Calculate sum of digits
    int m = atoi(N); // Convert input string to integer

    // Check if the number is divisible by the sum of its digits
    if (m % digit_sum == 0) {
=======
    int sum = digit_sum(N); // Calculate sum of digits
    int m = atoi(N); // Convert input string to integer

    // Check if the number is divisible by the sum of its digits
    if (sum != 0 && m % sum == 0) {
>>>>>>> 98c87cb78a (data updated)
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
