#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, k;
    scanf("%d %d", &num, &k);
    
    int *arr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int *different = (int *)malloc(num * sizeof(int));
    int different_count = 0;
    int temp = 0;

    for (int i = 0; i < num; i++) {
        int x = arr[i];
        int found = 0;

        // Check if x // k is in different
        for (int j = 0; j < different_count; j++) {
            if (different[j] == x / k) {
                found = 1;
                break;
            }
        }

        if (x % k != 0 || !found) {
            different[different_count++] = x;
        }
        if (different_count > temp) {
            temp = different_count;
        }
    }

    printf("%d\n", temp);

    free(arr);
    free(different);
    return 0;
}

// <END-OF-CODE>
