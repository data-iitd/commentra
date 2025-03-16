#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    // Calculate the sum of the first k elements
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    printf("%d\n", sum);

    free(arr);
    return 0;
}

// <END-OF-CODE>
