// C code starts here
#include <stdio.h>
#include <string.h>

int main() {
	char s[1000];
	scanf("%s", s);

	int n = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'o') {
			n++;
		}
	}

	int result = 700 + n*100;
	printf("%d\n", result);
}
// C code ends here

