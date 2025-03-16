
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to read input from standard input
char* input() {
    char* str = (char*)malloc(sizeof(char) * 1000000);
    scanf("%s", str);
    return str;
}

// Define the modulus value
int mod = 1000000007;

// Function to return an integer input
int I() {
    return atoi(input());
}

// Function to return a list of integers as input
int* III() {
    int* arr = (int*)malloc(sizeof(int) * 1000000);
    char* str = input();
    char* token = strtok(str, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to create a list of lists based on the given number of rows and columns
int** Line(int N, int num) {
    if (N <= 0) {
        int** arr = (int**)malloc(sizeof(int*) * 1);
        arr[0] = (int*)malloc(sizeof(int) * num);
        return arr;
    }
    else if (num == 1) {
        int** arr = (int**)malloc(sizeof(int*) * N);
        for (int i = 0; i < N; i++) {
            arr[i] = (int*)malloc(sizeof(int) * 1);
            arr[i][0] = I();
        }
        return arr;
    }
    else {
        int** arr = (int**)malloc(sizeof(int*) * N);
        for (int i = 0; i < N; i++) {
            arr[i] = (int*)malloc(sizeof(int) * num);
            for (int j = 0; j < num; j++) {
                arr[i][j] = I();
            }
        }
        return arr;
    }
}

// Initialize variables
int N = I();
int* a = III();
int max_val = 0;
int max_sign = 0;
int max_index = -1;

// Iterate through the list 'a' to find the maximum absolute value and its sign
for (int i = 0; i < N; i++) {
    // Update the maximum value and its sign if the current value is greater
    if (abs(a[i]) > max_val) {
        max_val = abs(a[i]);
        max_sign = my_sign(a[i]);
        max_index = i;
    }
}

// Determine the output based on the sign of the maximum value
if (max_sign == 0) {
    // If the maximum value is zero, print zero
    printf("0\n");
}
else if (max_sign == 1) {
    // If the maximum value is positive, print the required output
    printf("%d\n", 2 * N - 1);
    // Print the indices of the maximum value and the first element
    printf("%d %d\n", max_index + 1, 1);
    // Print the indices of the other elements in pairs
    for (int i = 1; i < N; i++) {
        printf("%d %d\n", i + 1, i + 2);
    }
}
else {
    // If the maximum value is negative, print the required output
    printf("%d\n", 2 * N - 1);
    // Print the indices of the maximum value and the first element
    printf("%d %d\n", max_index + 1, 1);
    // Print the indices of the other elements in reverse order
    for (int i = N - 1; i > 0; i--) {
        printf("%d %d\n", i + 1, i);
    }
}

// End of code
