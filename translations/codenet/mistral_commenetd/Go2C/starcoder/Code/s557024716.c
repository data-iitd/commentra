#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_K 100000

int main() {
	int a, b, c, k;
	scanf("%d %d %d %d", &a, &b, &c, &k);

	int patterns[MAX_K][MAX_N];
	int pattern_size = 0;
	int patterns_count = 1;
	int patterns_max_size = 1;
	int patterns_max_count = 1;

	for (int i = 0; i < 4; i++) {
		patterns[0][0] = i;
		pattern_size = 1;
		patterns_count = 1;
		for (int j = 1; j < k; j++) {
			patterns_count = 0;
			for (int p = 0; p < pattern_size; p++) {
				for (int q = 0; q < 4; q++) {
					patterns[j][patterns_count] = patterns[j - 1][p];
					if (patterns[j][patterns_count] == 0) {
						patterns[j][patterns_count] = q;
					} else if (patterns[j][patterns_count] == 1) {
						patterns[j][patterns_count] = q + 4;
					} else if (patterns[j][patterns_count] == 2) {
						patterns[j][patterns_count] = q + 8;
					} else if (patterns[j][patterns_count] == 3) {
						patterns[j][patterns_count] = q + 12;
					}
					patterns_count++;
				}
			}
			pattern_size = patterns_count;
		}
		if (patterns_count > patterns_max_count) {
			patterns_max_count = patterns_count;
			patterns_max_size = pattern_size;
		}
	}

	for (int i = 0; i < patterns_max_count; i++) {
		int r = a, g = b, b = c;
		for (int j = 0; j < patterns_max_size; j++) {
			if (patterns[j][i] == 0) {
				continue;
			} else if (patterns[j][i] == 1) {
				r *= 2;
			} else if (patterns[j][i] == 2) {
				g *= 2;
			} else if (patterns[j][i] == 3) {
				b *= 2;
			}
		}
		if (g > r && b > g) {
			printf("Yes");
			return 0;
		}
	}

	printf("No");
	return 0;
}

