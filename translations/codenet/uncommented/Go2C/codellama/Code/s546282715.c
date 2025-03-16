#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNextInt(FILE *fp) {
	char buf[100];
	fgets(buf, 100, fp);
	return atoi(buf);
}

int main(int argc, char *argv[]) {
	FILE *fp;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	} else {
		fp = stdin;
	}

	int n = getNextInt(fp);
	int m = getNextInt(fp);
	int *aa = (int *)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		aa[i] = getNextInt(fp);
	}

	int *dp = (int *)malloc(sizeof(int) * (n + 1));
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			int j = i + ii;
			if (aa[j] == 1) {
				continue;
			}
			dp[j] += dp[i];
			dp[j] %= 1000000007;
		}
	}
	printf("%d\n", dp[n]);

	free(aa);
	free(dp);
	return 0;
}

