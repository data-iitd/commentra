#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[100000];
    scanf("%s", S);

    char *divide[4] = {"dream", "dreamer", "erase", "eraser"};
    for (int i = 0; i < 4; ++i) {
        int len = strlen(divide[i]);
        for (int j = 0; j < len / 2; ++j) {
            char tmp = divide[i][j];
            divide[i][j] = divide[i][len - j - 1];
            divide[i][len - j - 1] = tmp;
        }
    }

    int can = 1;
    for (int i = 0; i < strlen(S);) {
        int can2 = 0;
        for (int j = 0; j < 4; ++j) {
            char *d = divide[j];
            if (strncmp(S + i, d, strlen(d)) == 0) {
                can2 = 1;
                i += strlen(d);
            }
        }
        if (!can2) {
            can = 0;
            break;
        }
    }

    if (can) printf("YES\n");
    else printf("NO\n");
}
