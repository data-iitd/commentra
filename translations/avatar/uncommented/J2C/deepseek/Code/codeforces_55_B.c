#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

long min = LONG_MAX;

void util(long *arr, char **ops, int idx, int size);

int main() {
    long arr[4];
    char *ops[3];
    for (int i = 0; i < 3; i++) {
        ops[i] = (char *)malloc(2 * sizeof(char));
    }
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%s", ops[i]);
    }
    util(arr, ops, 0, 4);
    printf("%ld\n", min);
    for (int i = 0; i < 3; i++) {
        free(ops[i]);
    }
    return 0;
}

void util(long *arr, char **ops, int idx, int size) {
    if (idx == 3) {
        min = (min < arr[0]) ? min : arr[0];
        return;
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            long res;
            long new_arr[size - 1];
            int k = 0;
            for (int l = 0; l < size; l++) {
                if (l != j && l != i) {
                    new_arr[k++] = arr[l];
                }
            }
            if (idx < 3 && strcmp(ops[idx], "+") == 0) {
                res = arr[i] + arr[j];
            } else {
                res = arr[i] * arr[j];
            }
            new_arr[k] = res;
            util(new_arr, ops, idx + 1, size - 1);
        }
    }
}

