#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

int mm[MAX_N+1];
int dp[MAX_N+1][MAX_N+1];

int getNextInt(FILE *fp) {
	int i;
	fscanf(fp, "%d", &i);
	return i;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	int n;
	int i, j, k;
	int l;
	int d;

	if (argc > 1) {
		fp = fopen(argv[1], "r");
	} else {
		fp = stdin;
	}

	n = getNextInt(fp);
	for (i = 0; i < n; i++) {
		mm[i] = getNextInt(fp);
		mm[i+1] = getNextInt(fp);
	}

	for (l = 2; l <= n; l++) {
		for (i = 1; i <= n-l+1; i++) {
			j = i + l - 1;
			for (k = i; k <= j-1; k++) {
				d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	printf("%d\n", dp[1][n]);

	return 0;
}

