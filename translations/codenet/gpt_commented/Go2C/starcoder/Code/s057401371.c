


#include <stdio.h>
#include <string.h>

int main() {
	char s[100000];
	scanf("%s", s);
	int d = 'a' - 'A';
	for (int i = 0; i < strlen(s); i++) {
		char rr = s[i];
		if ('A' <= s[i] && s[i] <= 'Z') {
			rr = s[i] + d;
		} else if ('a' <= s[i] && s[i] <= 'z') {
			rr = s[i] - d;
		}
		printf("%c", rr);
	}
	printf("\n");
}

