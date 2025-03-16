#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	char S[100000];
	scanf("%s", S);

	int x, y;
	scanf("%d %d", &x, &y);

	bool dpx[8000][20000];
	bool dpy[8000][20000];

	REP(i, 8000) REP(j, 20000) dpx[i][j] = false;
	REP(i, 8000) REP(j, 20000) dpy[i][j] = false;

	REP(i, 1000) {
		if (i % 2 == 0) {
			if (S[i] == '1') {
				REP(j, 2000) {
					if (j + 1000 <= 18000) dpx[i/2+1][j+1000] = dpx[i/2+1][j+1000] || dpx[i/2][j];
					if (j - 1000 >= 2000 && i/2!= 0) dpx[i/2+1][j-1000] = dpx[i/2+1][j-1000] || dpx[i/2][j];
				}
			}
		} else {
			if (S[i] == '1') {
				REP(j, 2000) {
					if (j + 1000 <= 18000) dpy[i/2+1][j+1000] = dpy[i/2+1][j+1000] || dpy[i/2][j];
					if (j - 1000 >= 2000) dpy[i/2+1][j-1000] = dpy[i/2+1][j-1000] || dpy[i/2][j];
				}
			}
		}
	}

	if (dpx[1000][x+10000] && dpy[1000][y+10000]) {
		printf("Yes");
	} else {
		printf("No");
	}

	return 0;
}

