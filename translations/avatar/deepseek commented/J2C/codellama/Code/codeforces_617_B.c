
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
            count++;
        }
    }
    if (count == 0) {
        printf("0");
    } else {
        long result = 1;
        for (int i = 1; i < count; i++) {
            result *= arr[i] - arr[i - 1];
        }
        printf("%ld", result);
    }
    free(arr);
    return 0;
}

