#include <stdio.h>

int main() {
    int S, W;
    scanf("%d %d", &S, &W);
    if (S <= W) {
        printf("unsafe\n");
    } else {
        printf("safe\n");
    }
    return 0;
}
