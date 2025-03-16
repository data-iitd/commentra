

#include <stdio.h>
#include <string.h>

int main() {
	char S[1000001];
	
	scanf("%s", S);
	
	for (int i = 2; i <= strlen(S); i = i + 2) {
		if (strncmp(S, S + strlen(S) - i, strlen(S) - i) == 0) {
			printf("%d\n", strlen(S) - i);
			break;
		}
	}
}

