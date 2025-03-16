#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_NUM 26

int memo[ALPHABET_NUM];
char str[1024];

int main() {
    while (fgets(str, sizeof(str), stdin) != NULL) {
        int len = strlen(str);
        if (len == 0) {
            break;
        }
        for (int i = 0; i < len; i++) {
            if (islower(str[i])) {
                memo[str[i] - 'a']++;
            } else if (isupper(str[i])) {
                memo[str[i] - 'A']++;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        printf("%c : %d\n", i + 'a', memo[i]);
    }

    return 0;
}

