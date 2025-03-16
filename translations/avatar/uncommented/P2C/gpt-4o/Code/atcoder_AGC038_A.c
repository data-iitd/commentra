#include <stdio.h>

void solve(int H, int W, int A, int B) {
    char answer[H][W + 1]; // +1 for null terminator

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
        answer[i][W] = '\0'; // Null terminate the string
    }

    for (int i = 0; i < H; i++) {
        printf("%s\n", answer[i]);
    }
}

int main() {
    int H, W, A, B;
    scanf("%d %d %d %d", &H, &W, &A, &B);
    solve(H, W, A, B);
    return 0;
}

// <END-OF-CODE>
