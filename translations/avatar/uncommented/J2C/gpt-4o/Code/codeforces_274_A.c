#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

int main() {
    int n;
    long long k;
    scanf("%d", &n);
    scanf("%lld", &k);
    
    long long *arr = (long long *)malloc(n * sizeof(long long));
    int *set = (int *)calloc(1000000, sizeof(int)); // Assuming values are within a certain range

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, n, sizeof(long long), compare);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            count++;
            set[arr[i]] = 1; // Mark this number as seen
        } else if (arr[i] / k < 1000000 && set[arr[i] / k] == 0) {
            count++;
            set[arr[i]] = 1; // Mark this number as seen
        }
    }

    printf("%d\n", count);

    free(arr);
    free(set);
    return 0;
}
