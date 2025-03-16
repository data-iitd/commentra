#include <stdio.h>
#include <string.h>

int main() {
	char s[100000];
	scanf("%s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = s[i] + ('a' - 'A');
		} else if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = s[i] - ('a' - 'A');
		}
	}
	printf("%s", s);
}

