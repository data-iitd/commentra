

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int x = 0, y = 0, t = 0, n = 0;
    char l[100001];
    scanf("%d", &n);
    scanf("%s", l);
    for (int i = 0; i < n; i++) {
        if (l[i]!= '4' && l[i]!= '7') {
            t = 1;
            break;
        }
    }
    if (t == 1) {
        printf("NO\n");
    } else {
        for (int i = 0; i < n / 2; i++) {
            x = x + l[i] - '0';
        }
        for (int i = n - 1; i > (n / 2) - 1; i--) {
            y = y + l[i] - '0';
        }
        if (x == y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
