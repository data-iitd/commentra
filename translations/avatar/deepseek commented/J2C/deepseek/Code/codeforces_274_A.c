#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    long long arr[n];
    bool set[n];
    for (int i = 0; i < n; i++) {
        set[i] = false;
    }

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, n, sizeof(long long), compare);

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            if (!set[i]) {
                count++;
                set[i] = true;
            }
        } else if (!set[i] && !set[(int)(arr[i] / k - 1)]) {
            count++;
            set[i] = true;
        }
    }

    printf("%d\n", count);
    return 0;
}
