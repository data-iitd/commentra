
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <float.h>
#include <assert.h>

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
bool valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return true;
    }
    return false;
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
int sumn(int i, int n) {
    return (n - i) * (i + n) / 2;
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
double sqfun(double a, double b, double c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single line of input and return it as a tuple of integers
int *value() {
    int *arr = (int *)malloc(sizeof(int) * 2);
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

// Function to read a single line of input from stdin and return it as a tuple of integers
int *values() {
    int *arr = (int *)malloc(sizeof(int) * 2);
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

// Function to read a single line of input and return it as a list of integers
int *inlst() {
    int *arr = (int *)malloc(sizeof(int) * 3);
    int i = 0;
    char *str = (char *)malloc(sizeof(char) * 100);
    scanf("%s", str);
    char *token = strtok(str, " ");
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read a single line of input from stdin and return it as a list of integers
int *inlsts() {
    int *arr = (int *)malloc(sizeof(int) * 3);
    int i = 0;
    char *str = (char *)malloc(sizeof(char) * 100);
    scanf("%s", str);
    char *token = strtok(str, " ");
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read a single integer from input
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single integer from stdin
int inps() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single line of input and return it as a string
char *instr() {
    char *str = (char *)malloc(sizeof(char) * 100);
    scanf("%s", str);
    return str;
}

// Function to read a single line of input and return it as a list of strings
char **stlst() {
    char **arr = (char **)malloc(sizeof(char *) * 3);
    int i = 0;
    char *str = (char *)malloc(sizeof(char) * 100);
    scanf("%s", str);
    char *token = strtok(str, " ");
    while (token != NULL) {
        arr[i++] = token;
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to process a string by removing specific characters and converting it to lowercase
char *f(char *s) {
    char *r = (char *)malloc(sizeof(char) * 100);
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] != '-' && s[i] != ';' && s[i] != '_') {
            r[i] = tolower(s[i]);
        }
        i++;
    }
    return r;
}

// Main function to solve the problem
void solve() {
    char **l = (char **)malloc(sizeof(char *) * 3);
    // Read three lines of input, process them, and store the results in a list
    for (int i = 0; i < 3; i++) {
        l[i] = f(instr());
    }

    // Generate all permutations of the processed strings
    int n = 3;
    int m = 1;
    for (int i = 2; i >= 0; i--) {
        m *= n--;
    }
    char **t = (char **)malloc(sizeof(char *) * m);
    int k = 0;
    for (int i = 0; i < m; i++) {
        t[i] = (char *)malloc(sizeof(char) * 100);
    }
    for (int i = 0; i < m; i++) {
        int j = i;
        for (int k = 0; k < 3; k++) {
            t[i][k] = l[j % 3][k];
            j /= 3;
        }
    }
    l = (char **)malloc(sizeof(char *) * m);
    for (int i = 0; i < m; i++) {
        l[i] = (char *)malloc(sizeof(char) * 100);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            l[i][j] = t[i][j];
        }
    }

    // Create a list of concatenated permutations
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            l[i][j] = t[i][j];
        }
    }

    // Read the number of test cases and check if the processed input is in the list of permutations
    int n = inp();
    for (int i = 0; i < n; i++) {
        char *str = (char *)malloc(sizeof(char) * 100);
        scanf("%s", str);
        int flag = 0;
        for (int j = 0; j < m; j++) {
            if (strcmp(str, l[j]) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
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

