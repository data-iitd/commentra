#include <stdio.h>
#include <string.h>

#define ALPHABET_NUM 26
#define MOD 1000000000 + 7

int main() {
	char str[100000 + 1];
	scanf("%s", str);

	int memo[ALPHABET_NUM];
	memset(memo, 0, sizeof(memo));

	for (int i = 0; str[i]!= '\0'; i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			memo[str[i] - 'a']++;
		} else if ('A' <= str[i] && str[i] <= 'Z') {
			memo[str[i] - 'A']++;
		}
	}

	for (int i = 0; i < ALPHABET_NUM; i++) {
		printf("%c : %d\n", i + 'a', memo[i]);
	}
}

