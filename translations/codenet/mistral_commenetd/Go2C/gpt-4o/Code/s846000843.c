#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} IntArray;

IntArray* createIntArray(int capacity) {
    IntArray *arr = (IntArray *)malloc(sizeof(IntArray));
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void appendIntArray(IntArray *arr, int value) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

void freeIntArray(IntArray *arr) {
    free(arr->data);
    free(arr);
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

IntArray* cumSum(int *nums, int n) {
    IntArray *sums = createIntArray(n + 1);
    appendIntArray(sums, 0);
    for (int i = 0; i < n; i++) {
        appendIntArray(sums, sums->data[i] + nums[i]);
    }
    return sums;
}

int main() {
    int n;
    scanf("%d", &n);

    int *aa = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }

    IntArray *cumsum = cumSum(aa, n);
    int ans = INT_MAX;

    for (int i = 1; i < cumsum->size - 1; i++) {
        int diff1 = abs(cumsum->data[cumsum->size - 1] - cumsum->data[i]);
        int diff2 = cumsum->data[i] - cumsum->data[0];
        ans = min(ans, min(diff1, diff2));
    }

    printf("%d\n", ans);

    free(aa);
    freeIntArray(cumsum);
    return 0;
}

// <END-OF-CODE>
