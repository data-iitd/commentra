#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
<<<<<<< HEAD
#include <time.h>

// Function to calculate the sum of digits
int sum_of_digits(const char *num_str) {
    int sum = 0;
    for (int i = 0; num_str[i] != '\0'; i++) {
        sum += num_str[i] - '0'; // Convert char to int
=======

// Function to calculate the sum of digits of a number
int sum_of_digits(const char *num_str) {
    int sum = 0;
    for (int i = 0; num_str[i] != '\0'; i++) {
        sum += num_str[i] - '0'; // Convert character to integer
>>>>>>> 98c87cb78a (data updated)
    }
    return sum;
}

// Main function
int main() {
<<<<<<< HEAD
    // Seed the random number generator
    srand(time(NULL));

    // Read input as a string
    char N[100]; // Assuming the input number will not exceed 99 digits
    scanf("%s", N);

    // Calculate the sum of digits
    int digit_sum = sum_of_digits(N);

    // Convert the string input to an integer
    long long m = atoll(N); // Convert string to long long

    // Check if the number is divisible by the sum of its digits
    if (digit_sum != 0 && m % digit_sum == 0) {
=======
    char N[100]; // Buffer to hold the input number as a string
    scanf("%s", N); // Read input as a string

    int sum = sum_of_digits(N); // Calculate the sum of digits
    int m = atoi(N); // Convert string input to an integer

    // Check if the number is divisible by the sum of its digits
    if (sum != 0 && m % sum == 0) {
>>>>>>> 98c87cb78a (data updated)
        printf("Yes\n"); // Print "Yes" if divisible
    } else {
        printf("No\n"); // Print "No" if not divisible
    }

<<<<<<< HEAD
    return 0;
}

// Utility functions (not used in this specific example but can be added if needed)

// Function to check if a value is within a range
bool in(int c, int a, int z) {
    return c >= a && c < z;
}

// Function to return the maximum value from a list of integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to return the minimum value from a list of integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    return (a < 0) ? -a : a;
}

// Function to print an array of integers
void print_ints(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

// Function to print an array of strings
void print_strings(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s", arr[i]);
        if (i != size - 1) {
            printf(" ");
        }
    }
    printf("\n");
=======
    return 0; // Return success
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
