#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, index, countMax = -1, array[1001] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &index);
        array[index]++;
    }
    for (i = 1; i < 1001; i++) {
        if (countMax < array[i]) {
            countMax = array[i];
        }
    }
    if (n % 2 == 0) {
        if (countMax <= n / 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        if (countMax <= n / 2 + 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

