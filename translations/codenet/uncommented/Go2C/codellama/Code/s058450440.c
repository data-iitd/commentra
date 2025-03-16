#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j, left, res, ans;
    char c;
    int a[100];
    int dic[100];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%c", &c);
        switch (c) {
        case 'M':
        case 'A':
        case 'R':
        case 'C':
        case 'H':
            dic[c]++;
        }
    }

    for (i = 0; i < 100; i++) {
        a[i] = dic[i];
    }

    ans = 0;
    for (left = 3; left > 0; left--) {
        for (i = 0; i < 100; i++) {
            for (j = i; j < 100; j++) {
                res = a[i] * a[j];
                if (left == 1) {
                    ans += res;
                } else {
                    for (k = j + 1; k < 100; k++) {
                        res *= a[k];
                        if (left == 2) {
                            ans += res;
                        } else {
                            for (l = k + 1; l < 100; l++) {
                                res *= a[l];
                                if (left == 3) {
                                    ans += res;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

