#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check if a sub-array of given size exists in a list
int help(int a, int b, int* l, int len) {
    int tot[b][a];
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

// Main function to solve the problem
void solve() {
    char x[1000];
    scanf("%s", x);
    int s[1000];
    int len = strlen(x);
    for (int i = 0; i < len; i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

    int tot[1000][2];
    int count = 0;
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s, len)) {
                tot[count][0] = 12 / i;
                tot[count][1] = i;
                count++;
            }
        }
    }

    printf("%d ", count);
    for (int i = 0; i < count; i++) {
        printf("%dx%d ", tot[i][0], tot[i][1]);
    }
    printf("\n");
}

// Main function to run the code
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
