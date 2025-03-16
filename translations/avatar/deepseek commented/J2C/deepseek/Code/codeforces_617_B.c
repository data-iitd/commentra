#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int indices[n];
    int index_count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) {
            indices[index_count++] = i;
        }
    }

    if (index_count == 0) {
        printf("0\n");
    } else {
        long long result = 1;
        for (int i = 1; i < index_count; i++) {
            result *= indices[i] - indices[i - 1];
        }
        printf("%lld\n", result);
    }

    return 0;
}
