#include <stdio.h>
#include <stdlib.h>

void solve(int H, int W, int A, int B) {
    char** answer = (char**)malloc(H * sizeof(char*));
    for (int i = 0; i < H; i++) {
        answer[i] = (char*)malloc(W * sizeof(char));
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < B) {
                if (j < A) {
                    answer[i][j] = '0';
                } else {
                    answer[i][j] = '1';
                }
            } else {
                if (j < A) {
                    answer[i][j] = '1';
                } else {
                    answer[i][j] = '0';
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printf("%c", answer[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < H; i++) {
        free(answer[i]);
    }
    free(answer);
}

int main() {
    int H, W, A, B;
    scanf("%d %d %d %d", &H, &W, &A, &B);
    solve(H, W, A, B);
    return 0;
}

