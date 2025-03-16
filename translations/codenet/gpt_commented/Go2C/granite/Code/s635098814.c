
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 1000000000000000000
#define INF_BIT60 1000000000000000000

int main() {
    char str[100001];
    int memo[ALPHABET_NUM] = {0};
    int i, c;

    while (scanf("%s", str)!= EOF) {
        if (strlen(str) == 0) {
            break;
        }

        for (i = 0; i < strlen(str); i++) {
            c = str[i];

            if ('a' <= c && c <= 'z') {
                // Increment count for lowercase letters.
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                // Increment count for uppercase letters.
                memo[c - 'A']++;
            } else {
                // Ignore non-alphabet characters.
                continue;
            }
        }

        // Print the count of each letter.
        for (i = 0; i < ALPHABET_NUM; i++) {
            printf("%c : %d\n", 'a' + i, memo[i]);
        }
    }

    return 0;
}
// END-OF-CODE