
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long min = LONG_MAX;

void util(long arr[], char ops[], int idx, int n) {
    if (idx == 3) {
        min = (min < arr[0])? min : arr[0];
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long a[n - 2];
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l!= j && l!= i) {
                    a[k++] = arr[l];
                }
            }
            long res;
            if (idx < 3 && ops[idx] == '+') {
                res = arr[i] + arr[j];
            } else {
                res = arr[i] * arr[j];
            }
            a[k++] = res;
            util(a, ops, idx + 1, n - 1);
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
    util(arr, ops, 0, 4);
    printf("%ld\n", min);
    return 0;
}

