#include <stdio.h>

int main() {
	char s[100];
	int price = 700;
	scanf("%s", s);

	for (int i = 0; i < 100; i++) {
		if (s[i] == 'o') {
			price += 100;
		}
	}
	printf("%d\n", price);

	return 0;
}

