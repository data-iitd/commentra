
#include <stdio.h>
#include <stdlib.h>

int get_nums(int num, int t) {
    int i, ans = 0;
    for (i = 0; i < num; i++) {
        if (i < t % num) {
            ans += t / num + 1;
        } else {
            ans += t / num;
        }
    }
    return ans;
}

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);
    int ans = get_nums(k, sk) + get_nums(n - k, sa - sk);
    printf("%d\n", ans);
    return 0;
}

