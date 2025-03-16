#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *ds = NULL;
	size_t ds_len = 0;
	getline(&ds, &ds_len, stdin);
	char *dd[1000];
	int dn[1000];
	int i, j, sum = 0;
	for (i = 0; i < 1000; i++) {
		dd[i] = strsep(&ds, " ");
		if (dd[i] == NULL) {
			break;
		}
		dn[i] = atoi(dd[i]);
	}
	for (i = 0; i < 1000; i++) {
		for (j = i + 1; j < 1000; j++) {
			sum += dn[i] * dn[j];
		}
	}
	printf("%d\n", sum);
	return 0;
}
