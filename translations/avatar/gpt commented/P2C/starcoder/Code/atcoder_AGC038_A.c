#include <stdio.h>

int main() {
    int H, W, A, B;
    scanf("%d %d %d %d", &H, &W, &A, &B);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < B) {
                if (j < A) {
                    printf("0");
                } else {
                    printf("1");
                }
            } else {
                if (j < A) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
        }
        printf("\n");
    }

    return 0;
}

