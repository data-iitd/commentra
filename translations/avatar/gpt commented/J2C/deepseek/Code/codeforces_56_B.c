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
    int isTrue = 0;

    for (int i = 0; i < len; i++) {
        if (a[i] != i + 1 && !flag) {
            l = i + 1;
            flag = 1;
            continue;
        }
        if (a[i] != i + 1 && flag) {
            r = i + 1;
            if (a[r - 1] > a[r - 2]) {
                isTrue = 1;
                break;
            }
        }
    }

    if (!isTrue) {
        printf("%d %d\n", l, r);
    } else {
        printf("0 0\n");
    }

    return 0;
}
