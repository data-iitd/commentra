#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int l, r;
    scanf("%d %d", &l, &r);
    int id = 0;
    for (int i = 1; i < n; i++) {
        int li, ri;
        scanf("%d %d", &li, &ri);
        if (li <= l && r <= ri) {
            id = i;
        } else if (li < l || r < ri) {
            id = n;
        }
        l = min(l, li);
        r = max(r, ri);
    }
    printf("%d\n", -1 if (id == n) else id + 1);
    return 0;
}

