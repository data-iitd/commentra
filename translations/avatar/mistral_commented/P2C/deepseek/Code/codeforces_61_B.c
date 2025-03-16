#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Function to check if given indices are valid
int valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return 1;
    }
    return 0;
}

// Function to calculate sum of first n natural numbers
int sumn(int i, int n) {
    return (n - i) * (i + n) / 2;
}

// Function to calculate square root of a number using quadratic formula
double sqfun(int a, int b, int c) {
    return (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
}

// Function to read a single line as a tuple of integers
void read_tuple(int *a, int *b) {
    scanf("%d %d", a, b);
}

// Function to read a single line as a list of integers
void read_list(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to read a single integer
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single integer from the standard input as a string
char* read_string() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read a list of integers
void read_list_of_ints(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function to solve the problem
void solve() {
    char l[3][100];
    for (int i = 0; i < 3; i++) {
        scanf("%s", l[i]);
    }
    int n = read_int();
    for (int i = 0; i < n; i++) {
        char s[100];
        scanf("%s", s);
        int found = 0;
        for (int j = 0; j < 6; j++) {
            if (strcmp(s, l[j / 2]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }
}

// Starting the program
int main() {
    solve();
    return 0;
}
