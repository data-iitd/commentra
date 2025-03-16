#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[100000];
    scanf("%s", S);

    int len = strlen(S);
    for (int i = 0; i < len / 2; ++i) {
        char tmp = S[i];
        S[i] = S[len - 1 - i];
        S[len - 1 - i] = tmp;
    }

    char divide[4][100] = {"dream", "dreamer", "erase", "eraser"};
    for (int i = 0; i < 4; ++i) {
        int len = strlen(divide[i]);
        for (int j = 0; j < len / 2; ++j) {
            char tmp = divide[i][j];
            divide[i][j] = divide[i][len - 1 - j];
            divide[i][len - 1 - j] = tmp;
        }
    }

    bool can = true;
    for (int i = 0; i < len; ++i) {
        bool can2 = false;
        for (int j = 0; j < 4; ++j) {
            if (strcmp(S + i, divide[j]) == 0) {
                can2 = true;
                i += strlen(divide[j]) - 1;
                break;
            }
        }
        if (!can2) {
            can = false;
            break;
        }
    }

    if (can) printf("YES\n");
    else printf("NO\n");
}

