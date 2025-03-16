#include <stdio.h>
#include <string.h>

int main() {
	char s[101];
	int n, i;

	scanf("%s", s);

	n = 0;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == 'o') {
			n++;
		}
	}

	printf("%d\n", 700 + n * 100);

	return 0;
}
