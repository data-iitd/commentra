#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, x, y, t;
    char l[100000];
    scanf("%d", &n);
    scanf("%s", l);
    t = 0;
    for (int i = 0; i < n; i++) {
        if (l[i]!= '4' && l[i]!= '7') {
            t = 1;
        }
    }
    if (t == 1) {
        printf("NO");
    } else {
        x = 0;
        y = 0;
        for (int i = 0; i < n / 2; i++) {
            x = x + (l[i] - '0');
        }
        for (int i = n - 1; i > (n / 2) - 1; i--) {
            y = y + (l[i] - '0');
        }
        if (x == y) {
            printf("YES");
        } else {
            printf("NO");
        }
    }
    return 0;
}

