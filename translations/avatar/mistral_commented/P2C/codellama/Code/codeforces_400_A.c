#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single value as a tuple
void value(int *a, int *b) {
    scanf("%d %d", a, b);
}

// Function to read multiple values as a tuple
void values(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
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
int inp() {
    int a;
    scanf("%d", &a);
    return a;
}

// Function to read a single value as an integer from stdin
int inps() {
    int a;
    scanf("%d", &a);
    return a;
}

// Function to read a single line as a string
char *instr() {
    char *a = (char *)malloc(1000000 * sizeof(char));
    scanf("%s", a);
    return a;
}

// Function to read a list of strings
char **stlst(int n) {
    char **a = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = (char *)malloc(1000000 * sizeof(char));
        scanf("%s", a[i]);
    }
    return a;
}

// Helper function to check if a sub-array of given size exists in a list
int help(int a, int b, int *l) {
    int tot[b];
    for (int i = 0; i < b; i++) {
        tot[i] = l[i * a] + l[i * a + 1] + l[i * a + 2];
    }
    for (int i = 0; i < b; i++) {
        if (tot[i] == b) {
            return 1;
        }
    }
    return 0;
}

// Main function to solve the problem
void solve() {
    char *x = instr();
    int s[1000000];
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

    int tot[12];
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot[i] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= 12; i++) {
        if (tot[i]) {
            cnt++;
        }
    }

    printf("%d ", cnt);
    for (int i = 1; i <= 12; i++) {
        if (tot[i]) {
            printf("%dx%d ", 12 / i, i);
        }
    }
    printf("\n");
}

// Main function to run the code
int main() {
    int t = inp();
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

