#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 100
#define MAX_PERM 720 // 6! permutations for 3 strings

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
int valid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
double sumn(int i, int n) {
    return (n - i) * (i + n) / 2.0;
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
double sqfun(double a, double b, double c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single integer from input
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to process a string by removing specific characters and converting it to lowercase
void f(char *s, char *result) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '-' && s[i] != ';' && s[i] != '_') {
            result[j++] = tolower(s[i]);
        }
    }
    result[j] = '\0'; // Null-terminate the string
}

// Function to generate all permutations of the strings
void permute(char arr[][MAX_LEN], int l, int r, char permutations[][MAX_LEN], int *count) {
    if (l == r) {
        strcpy(permutations[*count], arr[0]);
        (*count)++;
    } else {
        for (int i = l; i <= r; i++) {
            // Swap
            char temp[MAX_LEN];
            strcpy(temp, arr[l]);
            strcpy(arr[l], arr[i]);
            strcpy(arr[i], temp);
            permute(arr, l + 1, r, permutations, count);
            // Swap back
            strcpy(arr[i], arr[l]);
            strcpy(arr[l], temp);
        }
    }
}

// Main function to solve the problem
int main() {
    char inputStrings[3][MAX_LEN];
    char processedStrings[3][MAX_LEN];
    char permutations[MAX_PERM][MAX_LEN];
    int permCount = 0;

    // Read three lines of input, process them, and store the results in a list
    for (int i = 0; i < 3; i++) {
        scanf(" %[^\n]", inputStrings[i]); // Read a line of input
        f(inputStrings[i], processedStrings[i]);
    }

    // Generate all permutations of the processed strings
    permute(processedStrings, 0, 2, permutations, &permCount);

    // Read the number of test cases and check if the processed input is in the list of permutations
    int testCases = inp();
    for (int i = 0; i < testCases; i++) {
        char testString[MAX_LEN];
        char processedTestString[MAX_LEN];
        scanf(" %[^\n]", testString);
        f(testString, processedTestString);

        int found = 0;
        for (int j = 0; j < permCount; j++) {
            if (strcmp(processedTestString, permutations[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("ACC\n"); // Accepted
        } else {
            printf("WA\n");  // Wrong Answer
        }
    }

    return 0;
}

// <END-OF-CODE>
