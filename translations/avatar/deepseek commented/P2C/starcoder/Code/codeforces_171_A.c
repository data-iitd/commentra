#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    scanf("%s %s", a, b);

    int x = strlen(a) > strlen(b)? strlen(a) : strlen(b);

    char *pa = a, *pb = b;
    if (strlen(a) < strlen(b)) {
        pa = b;
        pb = a;
    }

    for (int i = 0; i < x; i++) {
        int d = (int)pb[i] + (int)pa[x - i - 1] + (int)('0' == pa[x - i - 1]);
        if (d > 9) {
            printf("%c", d - 10 + '0');
        } else {
            printf("%c", d + '0');
        }
    }

    if ('0' == pa[x - 1]) {
        printf("1");
    }

    printf("\n");

    return 0;
}

