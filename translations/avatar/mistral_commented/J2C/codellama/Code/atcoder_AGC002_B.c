#include <stdio.h>
#include <stdbool.h>

struct Box {
    int num;
    bool red;
};

void moveTo(struct Box *box, struct Box *other) {
    if (box->num == 0) {
        return;
    } else if (box->num == 1) {
        box->num = 0;
        other->num++;
        if (box->red) {
            other->red = true;
        }
        box->red = false;
    } else {
        box->num--;
        other->num++;
        if (box->red) {
            other->red = true;
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    struct Box *B = (struct Box *)malloc(N * sizeof(struct Box));

    // Initializing the first box with red color
    B[0].num = 1;
    B[0].red = true;

    // Initializing the remaining boxes with red color set to false
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = false;
    }

    // Reading the moves from the user and performing them on the boxes
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        moveTo(&B[x - 1], &B[y - 1]);
    }

    // Counting the number of red boxes
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++;
        }
    }

    // Printing the result
    printf("%d\n", counter);

    free(B);
    return 0;
}

