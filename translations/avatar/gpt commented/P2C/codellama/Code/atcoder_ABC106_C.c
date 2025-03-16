
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Defining constants for infinity, epsilon, and a modulus value
const int inf = 1000000000;
const double eps = 1.0 / 1000000000;
const int mod = 1000000007;

// Defining direction vectors for 4-way and 8-way movement
const int dd[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int ddn[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

// Function to read a line of integers from input
int* LI() {
    char* str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);
    int* arr = malloc(sizeof(int) * size);
    int i = 0;
    char* p = strtok(str, " ");
    while (p != NULL) {
        arr[i++] = atoi(p);
        p = strtok(NULL, " ");
    }
    free(str);
    return arr;
}

// Function to read a line of integers from input and convert them to zero-based index
int* LI_() {
    int* arr = LI();
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        arr[i] -= 1;
    }
    return arr;
}

// Function to read a line of floats from input
double* LF() {
    char* str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);
    double* arr = malloc(sizeof(double) * size);
    int i = 0;
    char* p = strtok(str, " ");
    while (p != NULL) {
        arr[i++] = atof(p);
        p = strtok(NULL, " ");
    }
    free(str);
    return arr;
}

// Function to read a line of strings from input
char** LS() {
    char* str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);
    char** arr = malloc(sizeof(char*) * size);
    int i = 0;
    char* p = strtok(str, " ");
    while (p != NULL) {
        arr[i++] = p;
        p = strtok(NULL, " ");
    }
    free(str);
    return arr;
}

// Function to read a single integer from input
int I() {
    char* str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);
    int i = atoi(str);
    free(str);
    return i;
}

// Function to read a single float from input
double F() {
    char* str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);
    double f = atof(str);
    free(str);
    return f;
}

// Function to read a single string from input
char* S() {
    char* str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);
    return str;
}

// Function to print a string and flush the output buffer
void pf(char* s) {
    printf("%s", s);
    fflush(stdout);
}

// Main function to process the input and return the result
int main() {
    // Reading a string from input
    char* s = S();
    // Reading an integer k from input
    int k = I();
    int l = 0;  // Initialize a counter for leading '1's

    // Count the number of leading '1's in the string
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '1') {
            break;
        }
        l++;
    }
    
    // If the count of leading '1's is greater than or equal to k, return 1
    if (l >= k) {
        return 1;
    }
    
    // Otherwise, return the character at position l in the string
    return s[l];
}

