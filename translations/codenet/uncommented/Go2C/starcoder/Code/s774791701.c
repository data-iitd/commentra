#include <stdio.h>

int main() {
	char s[1000];
	scanf("%s", s);

	int price = 700;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'o') {
			price += 100;
		}
	}
	printf("%d", price);
}
