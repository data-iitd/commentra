
#include <stdio.h>

int main() {
    int H, W, A, B;
    scanf("%d %d %d %d", &H, &W, &A, &B);
    if (W < 2 * A || H < 2 * B) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i < B && j < A) || (i >= B) && (j >= A)) {
                printf("0");
            } else {
                printf("1");
            }
        }
        printf("\n");
    }
    return 0;
}
// END-OF-CODE