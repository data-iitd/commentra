#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int red;
} Box;

void moveTo(Box *current, Box *other) {
    if (current->num == 0) {
        return;
    } else if (current->num == 1) {
        current->num = 0;
        other->num++;
        if (current->red) {
            other->red = 1;
        }
        current->red = 0;
    } else {
        current->num--;
        other->num++;
        if (current->red) {
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
