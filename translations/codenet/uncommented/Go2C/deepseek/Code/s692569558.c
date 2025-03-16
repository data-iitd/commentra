#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char input[1000];
	fgets(input, sizeof(input), stdin);
	fgets(input, sizeof(input), stdin);
	char *ds = strtok(input, " ");

	int dn[1000];
	int count = 0;
	while (ds != NULL) {
		dn[count++] = atoi(ds);
		ds = strtok(NULL, " ");
	}

	int sum = 0;
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			sum += dn[i] * dn[j];
		}
	}

	printf("%d\n", sum);
	return 0;
}
