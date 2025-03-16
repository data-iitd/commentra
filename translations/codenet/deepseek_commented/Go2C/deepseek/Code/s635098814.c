#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807
#define INF_BIT60 1152921504606846976

int memo[ALPHABET_NUM];
char str[100000];

void main() {
    while (fgets(str, sizeof(str), stdin) != NULL) {
        int len = strlen(str);
        if (len == 0) {
            break;
        }
        for (int i = 0; i < len; i++) {
            char c = str[i];
            if (islower(c)) {
                memo[c - 'a']++;
            } else if (isupper(c)) {
                memo[c - 'A']++;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        printf("%c : %d\n", i + 'a', memo[i]);
    }
}

