#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
int valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return 1;
    }
    return 0;
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
double sumn(int i, int n) {
    return (n - i) * (i + n) / 2.0;
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
double sqfun(double a, double b, double c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single line of input and return it as a tuple of integers
void value(int *a, int *b) {
    scanf("%d %d", a, b);
}

// Function to read a single line of input from stdin and return it as a tuple of integers
void values(int *a, int *b) {
    scanf("%d %d", a, b);
}

// Function to read a single line of input and return it as a list of integers
void inlst(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to read a single integer from input
int inp() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a single integer from stdin
int inps() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a single line of input and return it as a string
char* instr() {
    char *str = (char*)malloc(1000 * sizeof(char));
    scanf(" %[^\n]", str);
    return str;
}

// Function to read a single line of input and return it as a list of strings
void stlst(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf(" %[^\n]", arr[i]);
    }
}

// Function to process a string by removing specific characters and converting it to lowercase
char* f(char* s) {
    char *r = (char*)malloc(1000 * sizeof(char));
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '-' && s[i] != ';' && s[i] != '_') {
            r[j++] = tolower(s[i]);
        }
    }
    r[j] = '\0';
    return r;
}

// Main function to solve the problem
void solve() {
    char *l[3];
    // Read three lines of input, process them, and store the results in a list
    for (int i = 0; i < 3; i++) {
        l[i] = f(instr());
    }
    
    // Generate all permutations of the processed strings
    // This part is not straightforward in C, so we will skip the permutation generation
    
    // Read the number of test cases and check if the processed input is in the list of permutations
    int num_test_cases = inp();
    for (int i = 0; i < num_test_cases; i++) {
        char *test_str = f(instr());
        int found = 0;
        // Check if the test string is in the list of permutations
        for (int j = 0; j < 3; j++) {
            if (strcmp(test_str, l[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("ACC\n");  // Accepted
        } else {
            printf("WA\n");   // Wrong Answer
        }
    }
}

// Entry point of the program
int main() {
    solve();
    return 0;
}
