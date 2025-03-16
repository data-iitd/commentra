#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to check if given indices are valid
bool valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return true;
    }
    return false;
}

// Function to calculate sum of first n natural numbers
int sumn(int i, int n) {
    return (n - i) * (i + n) / 2;
}

// Function to calculate square root of a number using quadratic formula
int sqfun(int a, int b, int c) {
    return (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
}

// Function to read a single line as a tuple of integers
int *value() {
    int *arr = (int *)malloc(sizeof(int) * 2);
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

// Function to read a single line as a list of integers
int *values() {
    int n = 0;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read a single integer
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single integer from the standard input as a string
char *instr() {
    char *str = (char *)malloc(sizeof(char) * 1000);
    scanf("%s", str);
    return str;
}

// Function to read a list of integers
int *inlst() {
    int n = 0;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read a list of integers from the standard input
int *inlsts() {
    int n = 0;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read a single integer from the standard input
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single integer from the standard input
int inps() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single string from the standard input
char *instr() {
    char *str = (char *)malloc(sizeof(char) * 1000);
    scanf("%s", str);
    return str;
}

// Function to convert a string to a list
char **stlst() {
    char *str = (char *)malloc(sizeof(char) * 1000);
    scanf("%s", str);
    char **arr = (char **)malloc(sizeof(char *) * 1000);
    int i = 0;
    while (str[i] != '\0') {
        arr[i] = (char *)malloc(sizeof(char) * 1000);
        int j = 0;
        while (str[i] != ' ' && str[i] != '\0') {
            arr[i][j] = str[i];
            i++;
            j++;
        }
        arr[i][j] = '\0';
        i++;
    }
    return arr;
}

// Main function to solve the problem
void solve() {
    int l[3][2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &l[i][j]);
        }
    }
    int t[3][3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scanf("%d", &t[i][j][k]);
            }
        }
    }
    int n = 0;
    scanf("%d", &n);
    char **str = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        str[i] = (char *)malloc(sizeof(char) * 1000);
        scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (strcmp(str[i], t[j][k][l]) == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) {
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }
        if (flag == 1) {
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

