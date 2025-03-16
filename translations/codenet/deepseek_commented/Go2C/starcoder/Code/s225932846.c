#include <stdio.h>
#include <string.h>

int main() {
	char S[100000];
	scanf("%s", S);

	for (int i = 2; i <= strlen(S); i = i + 2) {
		if (strncmp(S, S + strlen(S) - i / 2, i / 2) == 0 && strncmp(S + strlen(S) - i / 2, S + strlen(S) - i, i / 2) == 0) {
			printf("%d\n", strlen(S) - i);
			break;
		}
	}
}

