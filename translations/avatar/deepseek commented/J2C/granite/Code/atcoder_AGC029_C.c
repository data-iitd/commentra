

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int n;
int a[100000];
int s[100000];

void set() {
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int isPossible(int k) {
    int i, j;
    memset(s, 0, sizeof(s));
    int current = 0;
    for (i = 0; i < n; i++) {
        if (a[i] <= current) {
            if (k == 1) return 0;
            while (s[a[i] - 1] >= k) {
                s[a[i] - 1] = 0;
                a[i]--;
            }
            int p = a[i] - 1;
            while (1) {
                if (p < 0) return 0;
                s[p]++;
                if (s[p] == k) {
                    s[p] = 0;
                    p--;
                } else {
                    break;
                }
            }
        }
        current = a[i];
    }
    return 1;
}

int main() {
    int ng = 0;
    int ok = n;
    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(k)) {
            ok = k;
        } else {
            ng = k;
        }
    }
    printf("%d\n", ok);
    return 0;
}

