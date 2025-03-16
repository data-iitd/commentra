
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
int valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return 1;
    }
    return 0;
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
int* value() {
    int* arr = (int*)malloc(2 * sizeof(int));
    int i = 0;
    char c;
    while ((c = getchar())!= '\n') {
        arr[i++] = c - '0';
    }
    return arr;
}

// Function to read a single line of input from stdin and return it as a tuple of integers
int* values() {
    int* arr = (int*)malloc(2 * sizeof(int));
    int i = 0;
    char c;
    while ((c = getchar())!= '\n') {
        arr[i++] = c - '0';
    }
    return arr;
}

// Function to read a single line of input and return it as a list of integers
int* inlst() {
    int* arr = (int*)malloc(10 * sizeof(int));
    int i = 0;
    char c;
    while ((c = getchar())!= '\n') {
        arr[i++] = c - '0';
    }
    return arr;
}

// Function to read a single line of input from stdin and return it as a list of integers
int* inlsts() {
    int* arr = (int*)malloc(10 * sizeof(int));
    int i = 0;
    char c;
    while ((c = getchar())!= '\n') {
        arr[i++] = c - '0';
    }
    return arr;
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
    int n = 100;
    char* str = (char*)malloc(n * sizeof(char));
    int i = 0;
    char c;
    while ((c = getchar())!= '\n') {
        str[i++] = c;
    }
    return str;
}

// Function to read a single line of input and return it as a list of strings
char** stlst() {
    int n = 10;
    char** arr = (char**)malloc(n * sizeof(char*));
    int i = 0;
    char c;
    while ((c = getchar())!= '\n') {
        arr[i++] = c;
    }
    return arr;
}

// Main function to solve the problem
void solve() {
    char* l[3];
    // Read three lines of input, process them, and store the results in a list
    for (int i = 0; i < 3; i++) {
        l[i] = instr();
        for (int j = 0; j < strlen(l[i]); j++) {
            if (l[i][j] == '-' || l[i][j] == ';' || l[i][j] == '_') {
                l[i][j] ='';
            }
            l[i][j] = tolower(l[i][j]);
        }
    }
    
    // Generate all permutations of the processed strings
    char* t[6];
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                t[index++] = (char*)malloc(strlen(l[i]) + strlen(l[j]) + strlen(l[k]) + 1);
                strcpy(t[index - 1], l[i]);
                strcat(t[index - 1], l[j]);
                strcat(t[index - 1], l[k]);
            }
        }
    }
    
    // Create a list of concatenated permutations
    char** l2 = (char**)malloc(6 * sizeof(char*));
    for (int i = 0; i < 6; i++) {
        l2[i] = (char*)malloc(strlen(t[i]) * 2 + 1);
        strcpy(l2[i], t[i]);
        strcat(l2[i], t[i]);
    }
    
    // Read the number of test cases and check if the processed input is in the list of permutations
    int n = inp();
    for (int i = 0; i < n; i++) {
        char* s = instr();
        for (int j = 0; j < strlen(s); j++) {
            if (s[j] == '-' || s[j] == ';' || s[j] == '_') {
                s[j] ='';
            }
            s[j] = tolower(s[j]);
        }
        int flag = 0;
        for (int j = 0; j < 6; j++) {
            if (strcmp(s, l2[j]) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
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

Translate the above C code to Java and end with comment "