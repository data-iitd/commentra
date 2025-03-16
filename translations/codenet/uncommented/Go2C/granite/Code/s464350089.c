
#include <stdio.h>

int main() {
    int h, n, a, i;

    scanf("%d %d", &h, &n);
    a = 0;
    for (i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        a += tmp;
    }

    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
