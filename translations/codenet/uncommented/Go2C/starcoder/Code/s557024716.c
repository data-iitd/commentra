#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int k;
	scanf("%d", &k);

	int patterns[4][4] = {
		{0, 1, 2, 3},
		{0, 1, 3, 2},
		{0, 2, 1, 3},
		{0, 2, 3, 1},
		{0, 3, 1, 2},
		{0, 3, 2, 1},
		{1, 0, 2, 3},
		{1, 0, 3, 2},
		{1, 2, 0, 3},
		{1, 2, 3, 0},
		{1, 3, 0, 2},
		{1, 3, 2, 0},
		{2, 0, 1, 3},
		{2, 0, 3, 1},
		{2, 1, 0, 3},
		{2, 1, 3, 0},
		{2, 3, 0, 1},
		{2, 3, 1, 0},
		{3, 0, 1, 2},
		{3, 0, 2, 1},
		{3, 1, 0, 2},
		{3, 1, 2, 0},
		{3, 2, 0, 1},
		{3, 2, 1, 0},
	};

	for (int i = 0; i < (1 << k); i++) {
		int r = a, g = b, b = c;
		for (int j = 0; j < k; j++) {
			if (patterns[i][j] == 0) {
				continue;
			} else if (patterns[i][j] == 1) {
				r *= 2;
			} else if (patterns[i][j] == 2) {
				g *= 2;
			} else if (patterns[i][j] == 3) {
				b *= 2;
			}
		}

		if (g > r && b > g) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");

	return 0;
}

