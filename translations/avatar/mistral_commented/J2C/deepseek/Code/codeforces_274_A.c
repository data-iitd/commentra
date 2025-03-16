#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(long*)a - *(long*)b);
}

int main() {
    int n;
    long k;
    scanf("%d %ld", &n, &k);

    long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    qsort(arr, n, sizeof(long), compare);

    int count = 0;
    bool set[n];
    for (int i = 0; i < n; i++) {
        set[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            if (!set[i]) {
                count++;
                set[i] = true;
            }
        } else if (!set[i] && arr[i] / k < n && !set[arr[i] / k]) {
            count++;
            set[i] = true;
        }
    }

    printf("%d\n", count);
    return 0;
}

