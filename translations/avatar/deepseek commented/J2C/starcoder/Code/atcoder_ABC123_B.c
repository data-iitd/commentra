#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int main() {
    int a[5];
    int r[5];
    int b;
    int ans = 0;
    int idx = 0;
    int last = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;
        if (r[i]!= 0) {
            b = 10 - r[i];
            if (b > last) {
                last = b;
                idx = i;
            }
        }
    }
    if (last == 0) {
        for (int i = 0; i < 5; i++) {
            ans += a[i];
        }
        printf("%d\n", ans);
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (i!= idx) {
            if (a[i] % 10 == 0) {
                ans += a[i];
            } else {
                ans += a[i] + (10 - r[i]);
            }
        }
    }
    ans += last;
    printf("%d\n", ans);
    return 0;
}

