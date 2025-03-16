#include <stdio.h>

int main() {
    int a, b, c = 0;
    scanf("%d %d", &a, &b);

    if (a == 1 && b == 1) {
        printf("0\n");
    } else {
        while (a >= 1 || b >= 1) {
            if (a >= b) {
                b++;
                a -= 2;
            } else {
                a++;
                b -= 2;
            }
            if (a <= 0 || b <= 0) {
                c++;
                break;
            }
            c++;
        }
        printf("%d\n", c);
    }

    return 0;
}

// <END-OF-CODE>
