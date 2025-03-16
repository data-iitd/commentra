
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807
#define INF_BIT60 1ULL << 60

int memo[ALPHABET_NUM];
char str[100001];

int main() {
    while (scanf("%s", str)!= EOF) {
        memset(memo, 0, sizeof(memo));
        for (int i = 0; str[i]!= '\0'; i++) {
            char c = str[i];
            if ('a' <= c && c <= 'z') {
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                memo[c - 'A']++;
            } else {
                continue;
            }
        }
        for (int i = 0; i < ALPHABET_NUM; i++) {
            printf("%c : %d\n", 'a' + i, memo[i]);
        }
    }
    return 0;
}
