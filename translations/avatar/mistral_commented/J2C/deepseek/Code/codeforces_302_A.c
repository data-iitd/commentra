#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, *arr, l, r, o = 0, e = 0;
    scanf("%d %d", &n, &k);
    arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) o++;
        else e++;
    }

    for (int i = 0; i < k; i++) {
        scanf("%d %d", &l, &r);
        if ((r - l + 1) % 2 == 1) {
            printf("0\n");
        } else {
            if ((r - l + 1) / 2 <= o) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }

    free(arr);
    return 0;
}

