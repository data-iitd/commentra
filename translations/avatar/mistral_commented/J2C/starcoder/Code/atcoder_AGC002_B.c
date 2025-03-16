#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, x, y, counter = 0;
    scanf("%d %d", &N, &M);
    struct Box {
        int num;
        int red;
    } B[N];
    B[0].num = 1;
    B[0].red = 1;
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = 0;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (B[x].num == 0) {
            continue;
        }
        B[x].num--;
        B[y].num++;
        if (B[x].red) {
            B[y].red = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}

