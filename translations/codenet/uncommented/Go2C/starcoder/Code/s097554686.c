#include <stdio.h>
#include <stdlib.h>

#define size 100001

int main() {
    int n, t, l, r, mem[size];
    scanf("%d", &n);
    scanf("%d", &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l);
        scanf("%d", &r);
        mem[l] += 1;
        mem[r] -= 1;
    }
    int ans = mem[0];
    for (int i = 1; i < t + 1; i++) {
        mem[i] += mem[i - 1];
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
