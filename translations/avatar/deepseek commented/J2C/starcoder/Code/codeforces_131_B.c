
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int N = 100005;
    long cnt[21];
    for (int i = 0; i < n; i++) {
        scanf("%d", &cnt[scan.nextInt() + 10]);
    }
    long res = 0;
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2;
    printf("%ld", res);
    return 0;
}

