#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[1000000];
	char c = 'a';
	int i, j;
	scanf("%s", s);
	for (j = 0; j < 26; j++) {
		int found = 0;
		for (i = 0; i < strlen(s); i++) {
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
