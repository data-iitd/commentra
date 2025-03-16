#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x;
    scanf("%d", &x);

    if (x != 2 && x % 2 == 0) {
        x++;
    }

    while (1) {
        int i;
        double sqrtNum = sqrt(x);

        for (i = 3; i <= sqrtNum; i += 2) {
            if (x % i == 0) {
                break;
            }
        }

        if (i > sqrtNum) {
            break;
        }

        x += 2;
    }

    printf("%d\n", x);

    return 0;
}

