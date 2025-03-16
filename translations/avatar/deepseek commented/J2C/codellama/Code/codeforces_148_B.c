
#include <stdio.h>

int main ( ) {
    int VP, VD, T, F, C, answer = 0, start = T;
    scanf("%d %d %d %d %d", &VP, &VD, &T, &F, &C);

    if (VD <= VP) {
        printf("0\n");
        return 0;
    }

    while (1) {
        double x = start * VP / (VD - VP);

        if ((start + x) * VP >= C) {
            break;
        }

        start += 2 * x + F;
        answer++;
    }

    printf("%d\n", answer);

    return 0;
}

