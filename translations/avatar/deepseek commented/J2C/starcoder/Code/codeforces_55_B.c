#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long min = LLONG_MAX;
    long arr[4];
    char ops[3];
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%c", &ops[i]);
    }
    util(arr, ops, 0);
    printf("%ld\n", min);
    return 0;
}

void util(long arr[], char ops[], int idx) {
    if (idx == 3) {
        min = min < arr[0]? min : arr[0];
        return;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            long a[3];
            int k = 0;
            for (int l = 0; l < 4; l++) {
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
            util(a, ops, idx + 1);
        }
    }
}

