

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long a[4];
    for (int i = 0; i < 4; i++) {
        scanf("%lld", &a[i]);
    }
    long long result = a[0] * a[2] > a[1] * a[3]? a[0] * a[2] : a[1] * a[3];
    result = result > a[0] * a[3]? result : a[0] * a[3];
    result = result > a[1] * a[2]? result : a[1] * a[2];
    printf("%lld\n", result);
    return 0;
}

