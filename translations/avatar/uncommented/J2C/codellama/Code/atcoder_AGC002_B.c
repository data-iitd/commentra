
#include <stdio.h>
#include <stdbool.h>

struct Box {
    int num;
    bool red;
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    struct Box B[N];
    B[0].num = 1;
    B[0].red = true;
    for (int i = 1; i < N; i++) {
        B[i].num = 1;
        B[i].red = false;
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
                B[y].red = true;
            }
            B[x].red = false;
        } else {
            B[x].num--;
            B[y].num++;
            if (B[x].red) {
                B[y].red = true;
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
    return 0;
}

