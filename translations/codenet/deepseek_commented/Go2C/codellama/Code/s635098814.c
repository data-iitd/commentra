#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807
#define INF_BIT60 1 << 60

int memo[ALPHABET_NUM];
char str[100000];

int main() {
    int i, j;
    char c;

    while (scanf("%s", str) != EOF) {
        for (i = 0; i < strlen(str); i++) {
            c = str[i];

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

    for (i = 0; i < ALPHABET_NUM; i++) {
        printf("%c : %d\n", i+'a', memo[i]);
    }

    return 0;
}

