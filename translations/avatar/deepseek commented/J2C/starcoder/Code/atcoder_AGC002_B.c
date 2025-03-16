
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, x, y, counter;
    scanf("%d %d", &N, &M);
    struct Box {
        int num;
        int red;
    } *B = (struct Box*)malloc(N * sizeof(struct Box));
    B[0].num = 1;
    B[0].red = 1;
    for (i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = 0;
    }
    for (i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        B[x].moveTo(B[y]);
    }
    counter = 0;
    for (i = 0; i < N; i++) {
        if (B[i].red) {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}

struct Box {
    int num;
    int red;
};

void Box_moveTo(struct Box *this, struct Box *other)
{
    if (this->num == 0) {
        return;
    } else if (this->num == 1) {
        this->num = 0;
        other->num++;
        if (this->red) {
            other->red = 1;
        }
        this->red = 0;
    } else {
        this->num--;
        other->num++;
        if (this->red) {
            other->red = 1;
        }
    }
}

