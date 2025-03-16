#include <stdio.h>
#include <string.h>

int main() {
    char S[100000];
    scanf("%s", S);

    // 後ろから解くかわりにすべての文字列を「左右反転」する
    for (int i = 0; i < strlen(S); ++i) S[i] = S[i] == 'e'? 'a' : 'e';
    for (int i = 0; i < 4; ++i) for (int j = 0; j < strlen(divide[i]); ++j) divide[i][j] = divide[i][j] == 'e'? 'a' : 'e';

    // 端から切っていく
    bool can = true;
    for (int i = 0; i < strlen(S);) {
        bool can2 = false; // 4 個の文字列たちどれかで divide できるか
        for (int j = 0; j < 4; ++j) {
            char d[100000];
            strcpy(d, divide[j]);
            if (strcmp(S + i, d) == 0) { // d で divide できるか
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

