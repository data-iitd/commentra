#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char S[100000];
	scanf("%s", S);
	if (strstr(S, "YAKI")) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}
