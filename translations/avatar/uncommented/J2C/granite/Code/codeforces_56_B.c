
#include <stdio.h>
#include <stdlib.h>

int main() {
    int len, a[100000], l, r, flag, isTrue;
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }
    l = 0;
    r = 0;
    flag = 0;
    isTrue = 0;
    for (int i = 0; i < len; i++) {
        if (a[i]!= i + 1 && flag == 0) {
            l = i + 1;
            flag = 1;
            continue;
        }
        if (a[i]!= i + 1 && flag == 1) {
            r = i + 1;
            if ((a[r - 1] - a[r - 2]) > 0) {
                isTrue = 1;
                break;
            }
        }
    }
    if (isTrue == 0) {
        printf("%d %d", l, r);
    } else {
        printf("0 0");
    }
    return 0;
}
//END-OF-CODE