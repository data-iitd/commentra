#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j, left, res, ans;
    char c;
    int a[5];
    int dic[5];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf(" %c", &c);
        switch (c) {
            case 'M':
                dic[0]++;
                break;
            case 'A':
                dic[1]++;
                break;
            case 'R':
                dic[2]++;
                break;
            case 'C':
                dic[3]++;
                break;
            case 'H':
                dic[4]++;
                break;
        }
    }

    for (i = 0; i < 5; i++) {
        a[i] = dic[i];
    }

    for (left = 3; left > 0; left--) {
        for (i = 0; i < 5; i++) {
            for (j = i + 1; j < 5; j++) {
                for (res = 1; res < 5; res++) {
                    if (res == i || res == j) {
                        continue;
                    }
                    ans += a[i] * a[j] * a[res];
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

