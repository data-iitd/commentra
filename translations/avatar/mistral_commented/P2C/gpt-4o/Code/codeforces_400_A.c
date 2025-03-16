#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to read a single integer
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a string
void instr(char *str) {
    scanf("%s", str);
}

// Helper function to check if a sub-array of given size exists in a list
int help(int a, int b, int *l) {
    int tot[MAX_SIZE][MAX_SIZE];
    int count = 0;

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            tot[count][j] = l[i * a + j];
        }
        count++;
    }

    for (int j = 0; j < a; j++) {
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += tot[i][j];
        }
        if (sum == b) {
            return 1;
        }
    }
    return 0;
}

// Main function to solve the problem
void solve() {
    char x[MAX_SIZE];
    instr(x);
    int s[MAX_SIZE];
    int tot[MAX_SIZE][2];
    int tot_count = 0;

    for (int i = 0; i < strlen(x); i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot[tot_count][0] = 12 / i;
                tot[tot_count][1] = i;
                tot_count++;
            }
        }
    }

    printf("%d ", tot_count);
    for (int i = 0; i < tot_count; i++) {
        printf("%dx%d ", tot[i][0], tot[i][1]);
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

// <END-OF-CODE>
