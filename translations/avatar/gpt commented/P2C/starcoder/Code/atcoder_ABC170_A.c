#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[100];
    int i;
    for (i = 0; i < 100; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 100; i++) {
        if (a[i] == 0) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}
