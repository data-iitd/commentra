#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000000001

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    int aPrev = 0;
    int valid = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > i || a[i] > aPrev + 1) {
            valid = 0;
            break;
        }
        if (a[i] == aPrev + 1) {
            ans++;
        } else {
            ans += a[i];
        }
        aPrev = a[i];
    }

    if (valid) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }

    return 0;
}

