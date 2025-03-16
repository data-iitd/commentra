#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Set the recursion limit to a higher value to handle deep recursions
#define RECURSION_LIMIT 10000000

// Define a modulo constant for later use
#define MOD 1000000007

// Function to read a line of input and strip the newline character
char* input() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    line[strlen(line) - 1] = '\0';
    return line;
}

// Function to read an integer from input
int I() {
    return atoi(input());
}

// Function to read a list of integers from input
int* II() {
    char* line = input();
    int* list = malloc(sizeof(int) * (strlen(line) + 1));
    int i = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        list[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    list[i] = 0;
    return list;
}

// Function to read a list of integers and return it as a list
int* III() {
    char* line = input();
    int* list = malloc(sizeof(int) * (strlen(line) + 1));
    int i = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        list[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    list[i] = 0;
    return list;
}

// Function to read a specific format of input based on the number of elements
int** Line(int N, int num) {
    // If N is less than or equal to 0, return an empty list
    if (N <= 0) {
        int** list = malloc(sizeof(int*) * num);
        for (int i = 0; i < num; i++) {
            list[i] = malloc(sizeof(int) * 1);
            list[i][0] = 0;
        }
        return list;
    }
    // If num is 1, read N integers and return them as a list
    else if (num == 1) {
        int** list = malloc(sizeof(int*) * N);
        for (int i = 0; i < N; i++) {
            list[i] = malloc(sizeof(int) * 1);
            list[i][0] = I();
        }
        return list;
    }
    // Otherwise, read N tuples of integers and return them as a transposed list
    else {
        int** read_all = malloc(sizeof(int*) * N);
        for (int i = 0; i < N; i++) {
            read_all[i] = II();
        }
        int** list = malloc(sizeof(int*) * num);
        for (int i = 0; i < num; i++) {
            list[i] = malloc(sizeof(int) * N);
            for (int j = 0; j < N; j++) {
                list[i][j] = read_all[j][i];
            }
        }
        return list;
    }
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

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

