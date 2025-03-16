
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int red;
} Box;

void moveTo(Box *b1, Box *b2) {
    if (b1->num == 0) {
        return;
    } else if (b1->num == 1) {
        b1->num = 0;
        b2->num++;
        if (b1->red) {
            b2->red = 1;
        }
        b1->red = 0;
    } else {
        b1->num--;
        b2->num++;
        if (b1->red) {
            b2->red = 1;
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Box *B = (Box*)malloc(N * sizeof(Box));
    B[0].num = 1;
    B[0].red = 1;
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = 0;
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        moveTo(&B[x - 1], &B[y - 1]);
    }
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++;
        }
    }
    printf("%d\n", counter);
    free(B);
    return 0;
}
