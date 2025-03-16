#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int help(int a, int b, int *l) {
    int *tot = (int *)malloc(b * sizeof(int));
    for (int i = 0; i < b; i++) {
        tot[i] = l[i * a];
    }
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j];
            if (sum == b) {
                free(tot);
                return 1;
            }
        }
    }
    free(tot);
    return 0;
}

void solve() {
    char x[13];
    scanf("%s", x);
    int s[12];
    int tot[12][2];
    int count = 0;

    for (int i = 0; i < 12; i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

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
        printf("%dx%d ", tot[i][0], tot[i][1]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
