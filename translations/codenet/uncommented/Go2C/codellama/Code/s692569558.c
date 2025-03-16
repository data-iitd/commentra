#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *s = NULL;
	int *dn = NULL;
	int i, j, sum = 0;
	int len = 0;

	scanf("%d", &len);
	scanf("%d", &len);
	s = (char *)malloc(len * sizeof(char));
	scanf("%s", s);

	dn = (int *)malloc(len * sizeof(int));
	for (i = 0; i < len; i++) {
		dn[i] = atoi(strtok(s, " "));
	}

	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			sum += dn[i] * dn[j];
		}
	}

	printf("%d\n", sum);

	free(s);
	free(dn);

	return 0;
}

