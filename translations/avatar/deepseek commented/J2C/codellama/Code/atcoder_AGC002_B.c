
#include <stdio.h>
#include <stdbool.h>

struct Box {
    int num;
    bool red;
};

void moveTo(struct Box *other, struct Box *current) {
    if (current->num == 0) {
        return;
    } else if (current->num == 1) {
        current->num = 0;
        other->num++;
        if (current->red) {
            other->red = true;
        }
        current->red = false;
    } else {
        current->num--;
        other->num++;
        if (current->red) {
            other->red = true;
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    struct Box *B = (struct Box *)malloc(N * sizeof(struct Box));
    B[0].num = 1;
    B[0].red = true;
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = false;
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        moveTo(&B[y], &B[x]);
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

