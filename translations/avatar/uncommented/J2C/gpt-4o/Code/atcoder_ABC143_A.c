#include <stdio.h>

int main() {
    int a, b, c;
    if (scanf("%d %d", &a, &b) == 2) {
        c = a - b * 2;
        if (c < 0) c = 0;
        printf("%d\n", c);
    }
    return 0;
}

// <END-OF-CODE>
