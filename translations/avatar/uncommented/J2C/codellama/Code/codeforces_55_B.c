
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_OPS 3
#define MAX_ARR 4

long min = LONG_MAX;

void util(long arr[], char ops[], int idx) {
    if (idx == MAX_OPS) {
        min = min < arr[0] ? min : arr[0];
        return;
    }
    for (int i = 0; i < MAX_ARR; i++) {
        for (int j = i + 1; j < MAX_ARR; j++) {
            long a[MAX_ARR - 1];
            int k = 0;
            for (int l = 0; l < MAX_ARR; l++) {
                if (l != j && l != i) {
                    a[k++] = arr[l];
                }
            }
            long res;
            if (idx < MAX_OPS && ops[idx] == '+') {
                res = arr[i] + arr[j];
            } else {
                res = arr[i] * arr[j];
            }
            a[k] = res;
            util(a, ops, idx + 1);
        }
    }
}

int main() {
    long arr[MAX_ARR];
    char ops[MAX_OPS];
    for (int i = 0; i < MAX_ARR; i++) {
        scanf("%ld", &arr[i]);
    }
    for (int i = 0; i < MAX_OPS; i++) {
        scanf(" %c", &ops[i]);
    }
    util(arr, ops, 0);
    printf("%ld\n", min);
    return 0;
}

