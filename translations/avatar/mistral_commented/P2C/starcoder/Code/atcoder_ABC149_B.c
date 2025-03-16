#include <stdio.h>
#include <stdlib.h>

int main() {
    int cookies[3];
    int leftOver;
    int takahashi;

    scanf("%d %d %d", &cookies[0], &cookies[1], &cookies[2]);

    leftOver = cookies[0] - cookies[2];
    takahashi = (leftOver > 0)? leftOver : 0;

    printf("%d %d", takahashi, (cookies[1] > takahashi)? cookies[1] : cookies[1] - abs(leftOver));

    return 0;
}
