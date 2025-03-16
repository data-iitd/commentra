#include <stdio.h>

int main() {
    int n, levels, level2, level3, count = 0;

    scanf("%d %d", &n, &levels);

    int arr[levels];
    for (int i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &level2);
    level3 = levels + level2;
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

