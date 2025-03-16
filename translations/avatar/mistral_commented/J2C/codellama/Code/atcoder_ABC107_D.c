
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int arr[MAX_N];
int sorted[MAX_N];
int bit[MAX_N * 2 + 2];

int n;

void init_bitmap(int n) {
    for (int i = n + 1; i < n * 2 + 2; i += i & -i) {
        bit[i]++;
    }
}

void update_bitmap(int x, int val) {
    for (int i = x + n + 1; i < n * 2 + 2; i += i & -i) {
        bit[i] += val;
    }
}

int query_bitmap(int x) {
    int sum = 0;
    for (int i = x + n; i > 0; i -= i & -i) {
        sum += bit[i];
    }
    return sum;
}

int solve(int arr[], int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = sorted[mid];
        int cur = 0;
        long cnt = 0;
        memset(bit, 0, sizeof(bit));
        init_bitmap(n);
        for (int i = 0; i < n; i++) {
            cur += arr[i] <= target ? 1 : -1;
            update_bitmap(cur + n + 1, 1);
            cnt += query_bitmap(cur + n);
        }
        if (cnt >= (long) n * (n + 1) / 2 + 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return sorted[l];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    memcpy(sorted, arr, sizeof(arr));
    qsort(sorted, n, sizeof(int), compare);
    printf("%d\n", solve(arr, n));
    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

