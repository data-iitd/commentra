#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char* divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    char S[100001];
    scanf("%s", S);

    // 後ろから解くかわりにすべての文字列を「左右反転」する
    int len = strlen(S);
    for (int i = 0; i < len; ++i) {
        S[i] = S[len - 1 - i];
    }
    for (int i = 0; i < 4; ++i) {
        int dlen = strlen(divide[i]);
        for (int j = 0; j < dlen; ++j) {
            divide[i][j] = divide[i][dlen - 1 - j];
        }
    }

    // 端から切っていく
    bool can = true;
    for (int i = 0; i < len;) {
        bool can2 = false; // 4 個の文字列たちどれかで divide できるか
        for (int j = 0; j < 4; ++j) {
            char* d = divide[j];
            int dlen = strlen(d);
            if (strncmp(&S[i], d, dlen) == 0) { // d で divide できるか
                can2 = true;
                i += dlen; // divide できたら i を進める
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
