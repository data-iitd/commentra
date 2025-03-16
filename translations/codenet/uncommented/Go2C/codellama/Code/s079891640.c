#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[100];
	int i;

	scanf("%s", s);

	for (i = 0; i < strlen(s); i++) {
		if (strstr(s + i + 1, s + i)) {
			printf("no\n");
			exit(0);
		}
	}

	printf("yes\n");

	return 0;
}

