#include <stdio.h>

int main() {
    int y;
    scanf("%d", &y);

    int arr[y];
    for (int i = 0; i < y; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < y; j++) {
            if (i == j) continue;
            for (int k = 0; k < y; k++) {
                if (k == i || k == j) continue;
                if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
                    printf("%d %d %d\n", k + 1, j + 1, i + 1);
                    return 0;
                }
            }
        }
    }

    printf("-1\n");
    return 0;
}
