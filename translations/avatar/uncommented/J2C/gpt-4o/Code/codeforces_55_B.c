#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

long min;

void util(long *arr, char ops[][2], int size, int idx) {
    if (idx == 3) {
        if (arr[0] < min) {
            min = arr[0];
        }
        return;
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            long *a = (long *)malloc((size - 1) * sizeof(long));
            int k = 0;
            for (int m = 0; m < size; m++) {
                if (m != j && m != i) {
                    a[k++] = arr[m];
                }
            }
            long res;
            if (idx < 3 && ops[idx][0] == '+') {
                res = arr[i] + arr[j];
            } else {
                res = arr[i] * arr[j];
            }
            a[k] = res; // Add the result to the new array
            util(a, ops, size - 1, idx + 1);
            free(a); // Free the allocated memory
        }
    }
}

int main() {
    min = LONG_MAX;
    long arr[4];
    char ops[3][2];

    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%s", ops[i]);
    }

    util(arr, ops, 4, 0);
    printf("%ld\n", min);

    return 0;
}
