#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, x, y, counter;
    scanf("%d %d", &N, &M);
    struct Box {
        int num;
        bool red;
        Box(int n, bool r) {
            num = n;
            red = r;
        }
        void moveTo(Box other) {
            if (num == 0) {
                return;
            } else if (num == 1) {
                num = 0;
                other.num++;
                if (red) {
                    other.red = true;
                }
                red = false;
            } else {
                num--;
                other.num++;
                if (red) {
                    other.red = true;
                }
            }
        }
    };
    Box *B = (Box*)malloc(sizeof(Box) * N);
    B[0] = Box(1, true);
    for (int i = 1; i < N; i++) {
        B[i] = Box(1, false);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        B[x].moveTo(B[y]);
    }
    counter = 0;
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}

