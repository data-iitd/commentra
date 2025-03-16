
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, levels, sum, sum2, sum3, count, i, j, x;
    int *arr, *arr2, *arr3;
    scanf("%d", &n);
    scanf("%d", &levels);
    arr = (int *)malloc(levels * sizeof(int));
    sum = 0;
    sum2 = 0;
    sum3 = 0;
    count = 0;
    for (i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &levels);
    arr2 = (int *)malloc((levels + levels) * sizeof(int));
    for (i = 0; i < levels; i++) {
        arr2[i] = arr[i];
    }
    for (i = levels; i < levels + levels; i++) {
        scanf("%d", &arr2[i]);
    }
    arr3 = (int *)malloc(n * sizeof(int));
    j = 0;
    for (i = 0; i < n; i++) {
        arr3[i] = ++j;
    }
    for (i = 0; i < n; i++) {
        for (x = 0; x < levels + levels; x++) {
            if (arr3[i] == arr2[x]) {
                count++;
                break;
            }
        }
    }
    if (count == n) {
        printf("I become the guy.\n");
    } else {
        printf("Oh, my keyboard!\n");
    }
    return 0;
}

