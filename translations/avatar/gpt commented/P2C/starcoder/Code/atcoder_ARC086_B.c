#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Set the recursion limit to a higher value to handle deep recursions
#define RECURSION_LIMIT 1000000
#define MAX_N 100000
#define MAX_A 1000000000

// Function to read a line of input and strip the newline character
char* input() {
    static char line[10000];
    fgets(line, 10000, stdin);
    return line;
}

// Function to read an integer from input
int I() {
    return atoi(input());
}

// Function to read a list of integers from input
int* II() {
    static int a[MAX_N];
    int N = I();
    for (int i = 0; i < N; i++) {
        a[i] = I();
    }
    return a;
}

// Function to read a list of integers and return it as a list
int* III() {
    static int a[MAX_N];
    int N = I();
    for (int i = 0; i < N; i++) {
        a[i] = I();
    }
    return a;
}

// Function to read a specific format of input based on the number of elements
int* Line(int N, int num) {
    // If N is less than or equal to 0, return an empty list
    if (N <= 0) {
        static int a[MAX_N];
        return a;
    }
    // If num is 1, read N integers and return them as a list
    else if (num == 1) {
        static int a[MAX_N];
        for (int i = 0; i < N; i++) {
            a[i] = I();
        }
        return a;
    }
    // Otherwise, read N tuples of integers and return them as a transposed list
    else {
        static int a[MAX_N][MAX_N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < num; j++) {
                a[i][j] = I();
            }
        }
        return a;
    }
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    // Read the number of elements
    int N = I();

    // Read the list of integers
    int* a = III();

    // Initialize variables to track the maximum absolute value, its sign, and index
    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Loop through the list to find the maximum absolute value and its properties
    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    // Check the sign of the maximum value and print results accordingly
    if (max_sign == 0) {
        // If the maximum sign is zero, print 0
        printf("0\n");
    }
    else if (max_sign == 1) {
        // If the maximum sign is positive, print the number of operations and the operations
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = 0; i < N - 1; i++) {
            printf("%d %d\n", i + 1, i + 2);
        }
    }
    else {
        // If the maximum sign is negative, print the number of operations and the operations
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = 1; i < N; i++) {
            printf("%d %d\n", i + 1, i);
        }
    }

    return 0;
}

