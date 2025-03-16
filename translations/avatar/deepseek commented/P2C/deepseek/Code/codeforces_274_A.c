#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int num, k;
    scanf("%d %d", &num, &k);
    int arr[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, num, sizeof(int), compare);
    int temp = 0;
    int different[num];
    int size = 0;

    for (int i = 0; i < num; i++) {
        int x = arr[i];
        int divisible = 0;
        for (int j = 0; j < size; j++) {
            if (different[j] == x / k) {
                divisible = 1;
                break;
            }
        }
        if (!divisible) {
            different[size++] = x;
        }
        temp = temp > size ? temp : size;
    }
    printf("%d\n", temp);
    return 0;
}
