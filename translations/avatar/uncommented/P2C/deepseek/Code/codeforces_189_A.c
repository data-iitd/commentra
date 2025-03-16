#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[4];
    int length;
    int ans = 0;

    // Read input
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    length = arr[0];

    // Sort the array except the first element
    for (int i = 1; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Check if the length can be divided by the largest element
    if (length % arr[0] == 0) {
        printf("%d\n", length / arr[0]);
        return 0;
    }

    // Calculate the maximum number of ribbons
    if (arr[0] == arr[1]) {
        for (int i = 0; i <= length / arr[2]; i++) {
            int check = length - i * arr[2];
            if (check >= 0 && check % arr[0] == 0) {
                int k = check / arr[0];
                if (k + i > ans) {
                    ans = k + i;
                }
            }
        }
    } else {
        for (int i = 0; i <= length / arr[2]; i++) {
            for (int j = 0; j <= length / arr[1]; j++) {
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    int k = check / arr[0];
                    if (k + i + j > ans) {
                        ans = k + i + j;
                    }
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
