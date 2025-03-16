
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n][n];
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    int flag = 0;
    char d1[n], d2[n];
    char rem[n * n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                d1[i] = s[i][j];
            }
            if (i == n - j - 1) {
                d2[i] = s[i][j];
            }
            if (i!= j && i!= n - j - 1) {
                rem[k] = s[i][j];
                k++;
            }
        }
    }
    if (k!= 1) {
        printf("NO\n");
    } else {
        int flag1 = 0, flag2 = 0, flag3 = 0;
        for (int i = 0; i < n; i++) {
            if (d1[i]!= d2[i]) {
                flag1 = 1;
            }
            if (d1[i]!= rem[0]) {
                flag2 = 1;
            }
        }
        if (flag1 == 0 && flag2 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
