

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c, k;
	scanf("%d%d%d%d", &a, &b, &c, &k);

	int patterns[100000][4];
	int num_patterns = 0;
	int pattern[4];
	int i, j;
	int r, g, b;
	int p;
	int ans = 0;

	for (i = 0; i < 4; i++) {
		pattern[i] = i;
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			patterns[num_patterns][0] = pattern[i];
			patterns[num_patterns][1] = pattern[j];
			num_patterns++;
		}
	}

	for (i = 0; i < num_patterns; i++) {
		r = a;
		g = b;
		b = c;
		for (j = 0; j < k; j++) {
			p = patterns[i][j];
			if (p == 0) {
				continue;
			} else if (p == 1) {
				r *= 2;
			} else if (p == 2) {
				g *= 2;
			} else if (p == 3) {
				b *= 2;
			}
		}
		if (g > r && b > g) {
			ans = 1;
			break;
		}
	}

	if (ans) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

/*
Sample input:
1 1 1 1

Sample output:
Yes
*/
