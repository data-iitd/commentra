
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[100000];
	scanf("%s", s);

	char c = 'a';
	for (int j = 0; j < 26; j++) {
		int found = 0;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == c) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			printf("%c\n", c);
			return 0;
		}
		c++;
	}

	printf("None\n");
	return 0;
}

