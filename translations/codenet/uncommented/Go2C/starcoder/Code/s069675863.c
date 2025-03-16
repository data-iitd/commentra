#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	char S[100000 + 1];
	scanf("%s", S);

	int x, y;
	scanf("%d %d", &x, &y);

	int F[100000 + 1];
	int cur = 0;
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == 'F') {
			cur++;
		} else {
			F[i] = cur;
			cur = 0;
		}
	}
	F[strlen(S)] = cur;

	int evens[100000 + 1];
	int odds[100000 + 1];
	int even_cnt = 0, odd_cnt = 0;
	for (int i = 0; i < strlen(S); i++) {
		if (i % 2 == 0) {
			evens[even_cnt++] = F[i];
		} else {
			odds[odd_cnt++] = F[i];
		}
	}

	bool dpx[100000 + 1][100000 + 1];
	bool dpy[100000 + 1][100000 + 1];
	memset(dpx, false, sizeof(dpx));
	memset(dpy, false, sizeof(dpy));
	dpx[0][10000] = true;
	dpy[0][10000] = true;
	for (int i = 0; i < even_cnt; i++) {
		int val = evens[i];
		for (int j = 2000; j <= 18000; j++) {
			if (j + val <= 18000) {
				dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
			}
			if (j - val >= 2000 && i!= 0) {
				dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
			}
		}
	}
	for (int i = 0; i < odd_cnt; i++) {
		int val = odds[i];
		for (int j = 2000; j <= 18000; j++) {
			if (j + val <= 18000) {
				dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
			}
			if (j - val >= 2000) {
				dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
			}
		}
	}

	if (dpx[even_cnt][x + 10000] && dpy[odd_cnt][y + 10000]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

