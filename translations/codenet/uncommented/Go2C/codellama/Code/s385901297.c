#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char line[100];
	int ns[4];
	fgets(line, 100, stdin);
	sscanf(line, "%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);

	qsort(ns, 4, sizeof(int), compare);
	if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

