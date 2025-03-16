
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 1000000

int main() {
    int n;
    int aa[MAX_INPUT];
    int cumsum[MAX_INPUT];
    int i;
    int ans = 2020202020;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }

    cumsum[0] = 0;
    for (i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i-1] + aa[i-1];
    }

    for (i = 1; i < n; i++) {
        ans = min(ans, abs(cumsum[n] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    printf("%d\n", ans);

    return 0;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int abs(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

