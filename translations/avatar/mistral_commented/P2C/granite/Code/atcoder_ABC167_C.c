
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Take input dimensions and threshold from user
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    // Initialize array 'c' with dimensions (n, m)
    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    // Initialize empty lists 'l' for storing combinations and'rem' for storing indices
    int l[m][m];
    int rem[m];
    int ans = 0;

    // Loop through all possible combinations of 'pre' indices
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            l[i][j] = 0;
        }
    }

    // Loop through each iteration 'i' of test cases
    for (int i = 1; i <= m; i++) {
        int ca = 0;
        for (int j = 0; j < i; j++) {
            ca += c[l[i][j], i];
        }
        if (ca < x) {
            rem[ans] = i;
            ans++;
        } else {
            continue;
        }
        if (ans > 0) {
            for (int j = 0; j < ans; j++) {
                l[i][j] = 0;
            }
            ans = 0;
        }
    }

    // If 'l' list is empty, print -1 and break the loop
    if (ans == 0) {
        printf("-1\n");
    } else {
        int ca = 0;
        for (int j = 0; j < ans; j++) {
            ca = 0;
            for (int k = 0; k < rem[j]; k++) {
                ca += c[l[rem[j]][k], 0];
            }
            if (ans == 0 || ca < ans) {
                ans = ca;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
