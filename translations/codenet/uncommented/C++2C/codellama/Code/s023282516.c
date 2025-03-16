#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char divide[4][10] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    char S[100];
    scanf("%s", S);

    // 後ろから解くかわりにすべての文字列を「左右反転」する
    int i = 0;
    while (S[i] != '\0') {
        S[i] = S[i] - 32;
        ++i;
    }
    for (int i = 0; i < 4; ++i) {
        int j = 0;
        while (divide[i][j] != '\0') {
            divide[i][j] = divide[i][j] - 32;
            ++j;
        }
    }

    // 端から切っていく
    bool can = true;
    i = 0;
    while (S[i] != '\0') {
        bool can2 = false; // 4 個の文字列たちどれかで divide できるか
        for (int j = 0; j < 4; ++j) {
            char *d = divide[j];
            if (strncmp(S + i, d, strlen(d)) == 0) { // d で divide できるか
                can2 = true;
                i += strlen(d); // divide できたら i を進める
            }
        }
        if (!can2) { // divide できなかったら
            can = false;
            break;
        }
    }

    if (can) printf("YES\n");
    else printf("NO\n");
}
