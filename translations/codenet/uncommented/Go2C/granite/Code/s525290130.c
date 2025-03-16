
#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int start, int end) {
    for (int i = start; i < (start + end) / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[end - 1 - i];
        arr[end - 1 - i] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int b, e;
        scanf("%d %d", &b, &e);
        reverse(arr, b, e);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
