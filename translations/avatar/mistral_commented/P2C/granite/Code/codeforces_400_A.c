
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single value as a tuple
void value(int *a, int *b) {
    scanf("%d %d", a, b);
}

// Function to read multiple values as a tuple
void values(int *a, int *b) {
    scanf("%d %d", a, b);
}

// Function to read a single value as a list
void inlst(int *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

// Function to read multiple values as a list
void inlsts(int *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

// Function to read a single value as an integer
void inp(int *a) {
    scanf("%d", a);
}

// Function to read a single value as an integer from stdin
void inps(int *a) {
    scanf("%d", a);
}

// Function to read a single line as a string
void instr(char *a, int n) {
    scanf("%s", a);
}

// Function to read a list of strings
void stlst(char **a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
}

// Helper function to check if a sub-array of given size exists in a list
int help(int *a, int n, int b) {
    int tot[b];
    for (int i = 0; i < b; i++) {
        tot[i] = a[i * n: i * n + n];
    }
    for (int i = 0; i < n; i++) {
        if (tot[i] == b) {
            return 1;
        }
    }
    return 0;
}

// Main function to solve the problem
void solve() {
    char x[1000];
    instr(x, 1000);
    int s[1000];
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

    int tot[1000];
    int count = 0;
    for (int i = 1; i < 13; i++) {
        if (12 % i == 0) {
            if (help(s, i, 12 / i)) {
                tot[count] = (12 / i);
                count++;
            }
        }
    }

    printf("%d ", count);
    for (int i = 0; i < count; i++) {
        printf("%dx%d ", tot[i], 12 / tot[i]);
    }
    printf("\n");
}

// Main function to run the code
int main() {
    int t;
    inp(&t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

Translate the above C code to Java and end with comment "