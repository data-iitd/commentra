#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long min = LONG_MAX;

void util(long *arr, char *ops, int idx) {
    if (idx == 3) {
        if (arr[0] < min) {
            min = arr[0];
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            long a[4];
            int k = 0, l = 0;
            for (int m = 0; m < 4; m++) {
                if (m != i && m != j) {
                    a[l++] = arr[m];
                }
            }

            long res;
            if (ops[idx] == '+') {
                res = arr[i] + arr[j];
            } else {
                res = arr[i] * arr[j];
            }

            a[2] = res;
            util(a, ops, idx + 1);
        }
    }
}

int main() {
    long arr[4];
    char ops[3];

    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }

    for (int i = 0; i < 3; i++) {
        scanf(" %c", &ops[i]);
    }

    util(arr, ops, 0);

    printf("%ld\n", min);

    return 0;
}

