
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[1000];
	scanf("%s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (strstr(s + i + 1, s[i])) {
			printf("no");
			exit(0);
		}
	}

	printf("yes");
}

