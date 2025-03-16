#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *s = malloc(100);
	scanf("%s", s);

	int d = 'a' - 'A';
	for (int i = 0; i < strlen(s); i++) {
		char r = s[i];
		if ('A' <= r && r <= 'Z') {
			r += d;
		} else if ('a' <= r && r <= 'z') {
			r -= d;
		}
		printf("%c", r);
	}
	printf("\n");
	return 0;
}

