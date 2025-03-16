#include <stdio.h>

int main() {
	char s[100];
	scanf("%s", s);
	if (strlen(s) >= 4 && strncmp(s, "YAKI", 4) == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
