#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, levels;
    scanf("%d %d", &n, &levels);

    int arr[levels];
    for (int i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }

    int level2;
    scanf("%d", &level2);
    int level3 = levels + level2;

    int arr2[level3];
    for (int i = 0; i < levels; i++) {
        arr2[i] = arr[i];
    }

    for (int i = levels; i < level3; i++) {
        scanf("%d", &arr2[i]);
    }

    int arr3[n];
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < level3; x++) {
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
