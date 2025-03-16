#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define mod 1000000007

int main() {
    int k;
    scanf("%d", &k);
    long long t = 0;
    for (int i = 1; i <= k; i++) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
