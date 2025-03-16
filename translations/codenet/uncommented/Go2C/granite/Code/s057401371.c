
#include <stdio.h>
#include <ctype.h>

int main() {
	char c;
	while ((c = getchar())!= EOF) {
		if (isupper(c)) {
			c += 'a' - 'A';
		} else if (islower(c)) {
			c -= 'a' - 'A';
		}
		putchar(c);
	}
	return 0;
}
