#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char divide[4][10] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    char S[100];
    scanf("%s", S);

    // 後ろから解くかわりにすべての文字列を「左右反転」する
    int len = strlen(S);
    for (int i = 0; i < len / 2; ++i) {
        char tmp = S[i];
        S[i] = S[len - i - 1];
        S[len - i - 1] = tmp;
    }
    for (int i = 0; i < 4; ++i) {
        int len = strlen(divide[i]);
        for (int j = 0; j < len / 2; ++j) {
            char tmp = divide[i][j];
            divide[i][j] = divide[i][len - j - 1];
            divide[i][len - j - 1] = tmp;
        }
    }

    // 端から切っていく
    bool can = true;
    for (int i = 0; i < len;) {
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
