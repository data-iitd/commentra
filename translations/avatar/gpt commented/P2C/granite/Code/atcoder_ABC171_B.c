
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int));

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    printf("%d\n", sum);

    free(arr);
    return 0;
}
