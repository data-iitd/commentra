#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int red;
} Box;

void moveTo(Box *self, Box *other) {
    if (self->num == 0) {
        return;
    } else if (self->num == 1) {
        self->num = 0;
        other->num++;
        if (self->red) {
            other->red = 1;
        }
        self->red = 0;
    } else {
        self->num--;
        other->num++;
        if (self->red) {
            other->red = 1;
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Box B[N];
    B[0] = (Box){1, 1};
    for (int i = 1; i < N; i++) {
        B[i] = (Box){1, 0};
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
    return 0;
}
