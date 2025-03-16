#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        if (value == 1) {
            arr[size++] = i;
        }
    }

    if (size == 0) {
        printf("0\n");
    } else {
        long result = 1;
        for (int i = 1; i < size; i++) {
            result *= arr[i] - arr[i - 1];
        }
        printf("%ld\n", result);
    }

    free(arr);
    return 0;
}

// <END-OF-CODE>
