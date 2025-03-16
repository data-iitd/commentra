#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[100];
	scanf("%s", s);

	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (s[i] == s[j]) {
				printf("no\n");
				return 0;
			}
		}
	}

	printf("yes\n");
	return 0;
}
