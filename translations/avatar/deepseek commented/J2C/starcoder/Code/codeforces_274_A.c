#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < n; i++) {
        if (arr[i] % k!= 0) {
            count++;
            set_add(arr[i]);
        } else if (!set_contains(arr[i] / k)) {
            count++;
            set_add(arr[i]);
        }
    }
    printf("%d", count);
    return 0;
}

