
#include <stdio.h>
#include <string.h>

int main() {
	char S[1000];
	scanf("%s", S);

	int i = 2;

	for(; i <= strlen(S); i += 2) {
		if(strncmp(S, S + strlen(S) - i/2, i/2) == 0 && strncmp(S + strlen(S) - i/2, S, i/2) == 0) {
			printf("%d\n", strlen(S) - i);
			break;
		}
	}
}

