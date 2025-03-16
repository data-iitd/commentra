#include <stdio.h>
#include <stdlib.h>

int main() {
    int cookies[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &cookies[i]);
    }
    int leftOver = cookies[0] - cookies[2];
    int takahashi = (leftOver > 0) ? leftOver : 0;
    printf("%d %d\n", takahashi, (takahashi > 0) ? cookies[1] : (cookies[1] > abs(leftOver) ? cookies[1] - abs(leftOver) : 0));
    return 0;
}
