

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	char S[1000010];
	int x, y;
	scanf("%s %d %d", S, &x, &y);

	int F[1000010];
	int cur = 0;
	REP(i, strlen(S)) {
		if (S[i] == 'F') {
			cur++;
		} else {
			F[i] = cur;
			cur = 0;
		}
	}
	F[strlen(S)] = cur;

	int evens[1000010], odds[1000010];
	int even_cnt = 0, odd_cnt = 0;
	REP(i, strlen(S)) {
		if (i % 2 == 0) {
			evens[even_cnt++] = F[i];
		} else {
			odds[odd_cnt++] = F[i];
		}
	}

	bool dpx[1000010][200010], dpy[1000010][200010];
	REP(i, 1000010) REP(j, 200010) {
		dpx[i][j] = false;
		dpy[i][j] = false;
	}
	dpx[0][10000] = true;
	dpy[0][10000] = true;

	REP(i, even_cnt) {
		int val = evens[i];
		REP(j, 200010) {
			if (j + val <= 18000) {
				dpx[i+1][j+val] = dpx[i+1][j+val] || dpx[i][j];
			}
			if (j - val >= 2000 && i!= 0) {
				dpx[i+1][j-val] = dpx[i+1][j-val] || dpx[i][j];
			}
		}
	}

	REP(i, odd_cnt) {
		int val = odds[i];
		REP(j, 200010) {
			if (j + val <= 18000) {
				dpy[i+1][j+val] = dpy[i+1][j+val] || dpy[i][j];
			}
			if (j - val >= 2000) {
				dpy[i+1][j-val] = dpy[i+1][j-val] || dpy[i][j];
			}
		}
	}

	if (dpx[even_cnt][x+10000] && dpy[odd_cnt][y+10000]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}
*/
