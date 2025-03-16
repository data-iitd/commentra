#include <stdio.h>
#include <string.h>

#define ALPHABET_NUM 26
#define MOD 1000000000 + 7

int memo[ALPHABET_NUM];

int main() {
	char str[100000 + 1];
	scanf("%s", str);

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

	for (int i = 0; i < ALPHABET_NUM; i++) {
		printf("%c : %d\n", i + 'a', memo[i]);
	}
}

// 