#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char s[n][n + 1]; // +1 for null terminator
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    
    int flag = 0;
    char d1[n]; // diagonal 1
    char d2[n]; // diagonal 2
    int rem[256] = {0}; // to track unique characters in the remaining positions
    int rem_count = 0;

    for (int i = 0; i < n; i++) {
        d1[i] = s[i][i]; // main diagonal
        d2[i] = s[i][n - i - 1]; // secondary diagonal
        for (int j = 0; j < n; j++) {
            if (i != j && i != n - j - 1) {
                if (rem[(int)s[i][j]] == 0) {
                    rem[(int)s[i][j]] = 1;
                    rem_count++;
                }
            }
        }
    }

    // Check conditions
    if (rem_count != 1) {
        printf("NO\n");
    } else {
        int d1_unique = 1, d2_unique = 1;
        for (int i = 1; i < n; i++) {
            if (d1[i] != d1[0]) {
                d1_unique = 0;
            }
            if (d2[i] != d2[0]) {
                d2_unique = 0;
            }
        }
        if (!d1_unique || !d2_unique || (d1[0] == d2[0])) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
