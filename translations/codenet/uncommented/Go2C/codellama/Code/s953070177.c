#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 500001

int getNextInt(FILE *fp) {
	char buffer[MAX_BUFFER_SIZE];
	fgets(buffer, MAX_BUFFER_SIZE, fp);
	return atoi(buffer);
}

int getNextInt64(FILE *fp) {
	char buffer[MAX_BUFFER_SIZE];
	fgets(buffer, MAX_BUFFER_SIZE, fp);
	return atol(buffer);
}

int main(int argc, char *argv[]) {
	FILE *fp;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	} else {
		fp = stdin;
	}

	int n = getNextInt(fp);

	int *aa = (int *)malloc((n + 2) * sizeof(int));
	int sum = 0;
	for (int i = 0; i < n; i++) {
		aa[i + 1] = getNextInt(fp);
		sum += abs(aa[i + 1] - aa[i]);
	}
	sum += abs(aa[n + 1] - aa[n]);

	for (int i = 1; i < n + 1; i++) {
		int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
		printf("%d\n", ans);
	}

	free(aa);
	return 0;
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

