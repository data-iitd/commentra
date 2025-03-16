#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int H, W, A, B;
    scanf("%d %d %d %d", &H, &W, &A, &B);
    char **answer = (char **)malloc(H * sizeof(char *));
    for (int i = 0; i < H; i++) {
        answer[i] = (char *)malloc(W * sizeof(char));
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
    return 0;
}
