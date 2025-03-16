#include <stdio.h>

#define SIZE 100001

int main() {
    int n, t;
    int mem[SIZE] = {0};

    scanf("%d %d", &n, &t);

    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        mem[l] += 1;
        mem[r] -= 1;
    }

    int ans = mem[0];

    for (int i = 1; i <= t; i++) {
        mem[i] += mem[i - 1];
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}
