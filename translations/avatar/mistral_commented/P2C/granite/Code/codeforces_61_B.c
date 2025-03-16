
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
int sqfun(int a, int b, int c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single line as a tuple of integers
void value(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

// Function to read a single line as a list of integers
void values(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

// Function to read a single integer
int inp() {
    int a;
    scanf("%d", &a);
    return a;
}

// Function to read a single integer from the standard input as a string
char* instr() {
    char a[1000];
    scanf("%s", a);
    return a;
}

// Function to read a list of integers
void inlst(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

// Function to read a list of integers from the standard input
void inlsts(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

// Function to read a single integer from the standard input
int inp() {
    int a;
    scanf("%d", &a);
    return a;
}

// Function to read a single integer from the standard input
int inps() {
    int a;
    scanf("%d", &a);
    return a;
}

// Function to read a single string from the standard input
char* instr() {
    char a[1000];
    scanf("%s", a);
    return a;
}

// Function to convert a string to a list
void stlst(char *a, char *b, char *c) {
    scanf("%s %s %s", a, b, c);
}

// Main function to solve the problem
void solve() {
    char a[1000], b[1000], c[1000];
    int l[3];
    for (int i = 0; i < 3; i++) {
        stlst(a, b, c);
        l[i] = strlen(a);
    }
    int t = inp();
    char s[1000];
    for (int i = 0; i < t; i++) {
        scanf("%s", s);
        int n = strlen(s);
        if (n!= l[0] + l[1] + l[2]) {
            printf("WA\n");
            continue;
        }
        int j = 0;
        for (int k = 0; k < 3; k++) {
            int m = l[k];
            if (j + m > n) {
                printf("WA\n");
                break;
            }
            if (strncmp(s + j, a, m)!= 0) {
                printf("WA\n");
                break;
            }
            j += m;
        }
        if (j == n) {
            printf("ACC\n");
        }
    }
}

// Starting the program
int main() {
    solve();
    return 0;
}

Translate the above C code to Java and end with comment "