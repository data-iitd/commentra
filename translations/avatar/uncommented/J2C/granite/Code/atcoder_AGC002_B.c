
#include <stdio.h>
#include <stdlib.h>

typedef struct Box {
    int num;
    int red;
} Box;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Box *B = (Box*)malloc(sizeof(Box) * N);
    B[0].num = 1;
    B[0].red = 1;
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = 0;
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (B[x].num == 0) {
            continue;
        } else if (B[x].num == 1) {
            B[x].num = 0;
            B[y].num++;
            if (B[x].red) {
                B[y].red = 1;
            }
            B[x].red = 0;
        } else {
            B[x].num--;
            B[y].num++;
            if (B[x].red) {
                B[y].red = 1;
            }
        }
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

