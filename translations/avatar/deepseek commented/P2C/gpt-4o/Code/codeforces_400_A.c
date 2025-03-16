#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to read a single integer from input
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single string from input
void instr(char *str) {
    scanf("%s", str);
}

// Helper function to check if a grid of given dimensions can be formed
int help(int a, int b, int *l) {
    int tot[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            tot[i][j] = l[i * a + j];
        }
    }
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if (sum == b) {
            return 1;
        }
    }
    return 0;
}

// Main solving function
void solve() {
    char x[MAX_SIZE];
    instr(x);
    int s[MAX_SIZE];
    int len = strlen(x);
    
    for (int i = 0; i < len; i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

    int tot[MAX_SIZE][2];
    int count = 0;

    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot[count][0] = 12 / i;
                tot[count][1] = i;
                count++;
            }
        }
    }

    printf("%d ", count);
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (tot[i][0] > tot[j][0] || (tot[i][0] == tot[j][0] && tot[i][1] > tot[j][1])) {
                int temp0 = tot[i][0], temp1 = tot[i][1];
                tot[i][0] = tot[j][0];
                tot[i][1] = tot[j][1];
                tot[j][0] = temp0;
                tot[j][1] = temp1;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%dx%d ", tot[i][0], tot[i][1]);
    }
    printf("\n");
}

// Main execution block
int main() {
    int t = inp();
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
