
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char S[1000000];
	scanf("%s", S);
	int l0 = 0, l1 = 0;
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == '0') {
			l0++;
		} else {
			l1++;
		}
	}
	printf("%d", 2 * min(l0, l1));
	return 0;
}

