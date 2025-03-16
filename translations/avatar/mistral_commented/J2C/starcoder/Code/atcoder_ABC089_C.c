
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    long cnt[5] = {0};
    for (int i = 0; i < n; ++i) {
        char str[100];
        scanf("%s", str);
        if (str[0] == 'M') {
            cnt[0]++;
        } else if (str[0] == 'A') {
            cnt[1]++;
        } else if (str[0] == 'R') {
            cnt[2]++;
        } else if (str[0] == 'C') {
            cnt[3]++;
        } else if (str[0] == 'H') {
            cnt[4]++;
        }
    }
    long res = cnt[0] * cnt[1] * cnt[2] + cnt[0] * cnt[1] * cnt[3] + cnt[0] * cnt[1] * cnt[4] + cnt[0] * cnt[2] * cnt[3] + cnt[0] * cnt[2] * cnt[4] + cnt[0] * cnt[3] * cnt[4] + cnt[1] * cnt[2] * cnt[3] + cnt[1] * cnt[2] * cnt[4] + cnt[1] * cnt[3] * cnt[4] + cnt[2] * cnt[3] * cnt[4];
    printf("%ld\n", res);
    return 0;
}

