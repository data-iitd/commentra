
#include <stdio.h>

int main() {
    int a[100];
    int i, e;
    for (i = 0; i < 100; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            e = i + 1;
            break;
        }
    }
    printf("%d\n", e);
    return 0;
}
// 