#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) {
            arr[count++] = i;
        }
    }

    if (count == 0) {
        printf("0\n");
    } else {
        long long result = 1;

        for (int i = 1; i < count; i++) {
            result *= arr[i] - arr[i - 1];
        }

        printf("%lld\n", result);
    }

    free(arr);
    return 0;
}

