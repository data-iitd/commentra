
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807
#define INF_BIT60 1 << 60

int main() {
	char str[100000];
	int memo[ALPHABET_NUM];
	int i, j;

	while (scanf("%s", str) != EOF) {
		for (i = 0; i < ALPHABET_NUM; i++) {
			memo[i] = 0;
		}
		for (i = 0; i < strlen(str); i++) {
			if ('a' <= str[i] && str[i] <= 'z') {
				// toUpper
				// c-('a'-'A')
				memo[str[i]-'a']++;
			} else if ('A' <= str[i] && str[i] <= 'Z') {
				// toLower
				// c+('a'-'A')
				memo[str[i]-'A']++;
			} else {
				// stay
				// c
				continue;
			}
		}
		for (i = 0; i < ALPHABET_NUM; i++) {
			printf("%c : %d\n", i+'a', memo[i]);
		}
	}

	return 0;
}

