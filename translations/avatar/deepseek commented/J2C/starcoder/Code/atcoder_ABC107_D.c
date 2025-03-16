
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_N 100000

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sorted[MAX_N];
    memcpy(sorted, arr, sizeof(int) * n);
    qsort(sorted, n, sizeof(int), cmpfunc);
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = sorted[mid];
        int cur = 0;
        int bit[2 * MAX_N + 2];
        memset(bit, 0, sizeof(int) * (2 * MAX_N + 2));
        for (int i = 0; i < n; i++) {
            cur += arr[i] <= target? 1 : -1;
            for (int x = cur + MAX_N + 1; x < 2 * MAX_N + 2; x += x & -x) {
                bit[x]++;
            }
        }
        if (bit[cur + MAX_N] >= (n + 1) / 2) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", sorted[l]);
    return 0;
}

