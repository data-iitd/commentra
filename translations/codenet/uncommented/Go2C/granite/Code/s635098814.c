

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 1000000000000000000
#define INF_BIT60 1000000000000000000

int memo[ALPHABET_NUM];
char str[1000000];

int main() {
    while (scanf("%s", str)!= EOF) {
        if (strlen(str) == 0) {
            break;
        }
        for (int i = 0; i < strlen(str); i++) {
            char c = str[i];
            if ('a' <= c && c <= 'z') {
                // toUpper
                // c-('a'-'A')
                memo[c-'a']++;
            } else if ('A' <= c && c <= 'Z') {
                // toLower
                // c+('a'-'A')
                memo[c-'A']++;
            } else {
                // stay
                // c
                continue;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        printf("%c : %d\n", 'a'+i, memo[i]);
    }

    return 0;
}

// MODはとったか？
// 遷移だけじゃなくて最後の最後でちゃんと取れよ？

