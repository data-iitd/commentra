#include <stdio.h>
#include <stdlib.h>

int main() {
    int len;
    scanf("%d", &len);

    int a[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }

    int l = 0;
    int r = 0;
    int flag = 0;

    for (int i = 0; i < len; i++) {
        if (a[i] != i + 1 && flag == 0) {
            l = i + 1;
            flag = 1;
            continue;
        }

        if (a[i] != i + 1 && flag == 1) {
            r = i + 1;
            if ((a[r - 1] - a[r - 2] > 0)) {
                printf("%d %d\n", l, r);
                return 0;
            }
        }
    }

    printf("0 0\n");
    return 0;
}
