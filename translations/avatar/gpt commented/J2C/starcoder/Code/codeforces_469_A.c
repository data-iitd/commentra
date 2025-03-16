#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, levels, sum, sum2, sum3, level2, level3, count, i, j;
    int *arr, *arr2, *arr3;

    scanf("%d %d", &n, &levels);
    arr = (int *) malloc(levels * sizeof(int));
    for (i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &level2);
    level3 = levels + level2;
    arr2 = (int *) malloc(level3 * sizeof(int));
    for (i = 0; i < levels; i++) {
        arr2[i] = arr[i];
    }
    for (i = levels; i < level3; i++) {
        scanf("%d", &arr2[i]);
    }
    arr3 = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < level3; j++) {
            if (arr3[i] == arr2[j]) {
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

