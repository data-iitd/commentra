
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, k;
    scanf("%d %d", &num, &k);

    int arr[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int different[num];
    int different_length = 0;
    for (int i = 0; i < num; i++) {
        if (arr[i] % k!= 0 || arr[i] / k!= different[arr[i] / k]) {
            different[arr[i]] = 1;
            different_length = different_length > different_length + 1? different_length : different_length + 1;
        }
    }

    printf("%d", different_length);

    return 0;
}

