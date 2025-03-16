#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] > 15) {
        printf("15\n");
    } else {
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] > 15) {
                printf("%d\n", arr[i - 1] + 15);
                break;
            }
        }
        if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90) {
            printf("90\n");
        } else {
            printf("%d\n", arr[n - 1] + 15);
        }
    }

    return 0;
}

