
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, levels, sum = 0, sum2 = 0, sum3 = 0, arr[100], count = 0, level2, level3, arr2[200], arr3[1000];
    scanf("%d %d", &n, &levels);
    for (int i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &level2);
    level3 = levels + level2;
    for (int i = 0; i < levels; i++) {
        arr2[i] = arr[i];
    }
    for (int i = levels; i < level3; i++) {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < level3; i++) {
    }
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
//END-OF-CODE