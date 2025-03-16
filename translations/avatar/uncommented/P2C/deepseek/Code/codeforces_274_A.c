#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, k;
    scanf("%d %d", &num, &k);
    int arr[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    int temp = 0;
    int different[num];
    int different_size = 0;
    for (int i = 0; i < num; i++) {
        int is_added = 0;
        for (int j = 0; j < different_size; j++) {
            if (arr[i] % k != 0 || arr[i] / k != different[j]) {
                is_added = 1;
                break;
            }
        }
        if (is_added) {
            different[different_size++] = arr[i];
        }
        temp = temp > different_size ? temp : different_size;
    }
    printf("%d\n", temp);
    return 0;
}
