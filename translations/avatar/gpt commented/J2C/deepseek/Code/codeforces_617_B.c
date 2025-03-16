#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int indices[n];
    int indexCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            indices[indexCount++] = i;
        }
    }

    if (indexCount == 0) {
        printf("0\n");
    } else {
        long result = 1;
        for (int i = 1; i < indexCount; i++) {
            result *= indices[i] - indices[i - 1];
        }
        printf("%ld\n", result);
    }

    return 0;
}
