#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int binarySearch(int *arr, int n, int target) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void mainFn() {
    int n = 0;
    scanf("%d", &n);
    int ls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ls[i]);
    }
    int lsRev[n];
    memcpy(lsRev, ls, n * sizeof(int));
    qsort(ls, n, sizeof(int), compare);
    qsort(lsRev, n, sizeof(int), compare);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            int x = q - p;
            int y = q + p;

            int l = binarySearch(ls, n, x);
            int r = n - binarySearch(lsRev, n, y);

            int sum = r - l;
            if ((i >= l && i <= r) || (j >= l && j <= r)) {
                sum--;
            }
            sum = sum > 0 ? sum : 0;
            ans += sum;
        }
    }

    ans /= 3;
    printf("%d\n", ans);
}

int main() {
    mainFn();
    return 0;
}
