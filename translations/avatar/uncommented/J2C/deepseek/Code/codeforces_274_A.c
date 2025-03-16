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
    bool set[1000001] = {false}; // Assuming the maximum value in arr is 1000000 for simplicity
    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            if (!set[(int)(arr[i])]) {
                count++;
                set[(int)(arr[i])] = true;
            }
        } else if (!set[(int)(arr[i] / k)]) {
            count++;
            set[(int)(arr[i] / k)] = true;
        }
    }
    printf("%d\n", count);
    return 0;
}
