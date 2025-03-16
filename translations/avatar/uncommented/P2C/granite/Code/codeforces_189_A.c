
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <signal.h>
#include <setjmp.h>

int main() {
    int arr[3];
    int length;
    scanf("%d", &length);
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, 3, sizeof(int), cmpfunc);
    int ans = 0;
    if (length % arr[0] == 0) {
        ans = length / arr[0];
    } else {
        int k = 0;
        for (int i = 0; i <= length / arr[2]; i++) {
            for (int j = 0; j <= (length - i * arr[2]) / arr[1]; j++) {
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    k = check / arr[0];
                    ans = max(ans, k + i + j);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

int cmpfunc(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

// END-OF-CODE