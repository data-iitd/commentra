#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define DEBUG 0

#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

#define min(a, b) ((a) < (b)? (a) : (b))
#define minll(a, b) ((a) < (b)? (a) : (b))
#define minf(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))
#define maxll(a, b) ((a) > (b)? (a) : (b))
#define maxf(a, b) ((a) > (b)? (a) : (b))
#define abs(a) ((a) < 0? -(a) : (a))
#define absll(a) ((a) < 0? -(a) : (a))
#define absf(a) ((a) < 0? -(a) : (a))

// egcd(a, b) returns d, x, y:
//   d is gcd(a,b)
//   x, y are  integers that satisfy ax + by = d
int64_t egcd(int64_t a, int64_t b) {
	if (b == 0) {
		return a;
	}
	int64_t d, x, y;
	d = egcd(b, a % b);
	x = y = 0;
	y = -a / b * x;
	return d;
}

int64_t gcd(int64_t a, int64_t b) {
	int64_t d;
	d = egcd(a, b);
	return d;
}

// set up IO functions
void init() {
	// for non-interactive
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// Enable below when interactive.  Its ok to leave above intact.
	// SetInteractive(stdin, stdout);
}

int main() {
	init();
	int h, w, k;
	scanf("%d %d %d", &h, &w, &k);
	int m[h][w];
	for (int i = 0; i < h; i++) {
		char s[w];
		scanf("%s", s);
		for (int j = 0; j < w; j++) {
			m[i][j] = s[j];
		}
	}

	int answer = solve(h, w, k, m);
	printf("%d\n", answer);
}

int countBlack(int h, int w, int m[h][w]) {
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m[i][j] == 'B') {
				count++;
			}
		}
	}
	return count;
}

int solve(int h, int w, int a, int m[h][w]) {
	int result = 0;
	for (int i = 0; i < (1 << h); i++) {
		for (int k = 0; k < (1 << w); k++) {
			int tmp[h][w];
			for (int j = 0; j < h; j++) {
				for (int l = 0; l < w; l++) {
					tmp[j][l] = m[j][l];
				}
			}
			for (int j = 0; j < h; j++) {
				int hPainted = (1 << j & i);
				if (hPainted > 0) {
					for (int l = 0; l < w; l++) {
						tmp[j][l] = 1;
					}
				}
			}
			for (int j = 0; j < w; j++) {
				int wPainted = (1 << j & k);
				if (wPainted > 0) {
					for (int l = 0; l < h; l++) {
						tmp[l][j] = 1;
					}
				}
			}
			if (countBlack(h, w, tmp) == a) {
				result++;
			}
		}
	}
	return result;
}

