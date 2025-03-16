#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int k;
	scanf("%d", &k);

	int patterns[100000][4];
	int pattern_num = 0;
	int pattern[4];
	REP(i, 4) {
		pattern[i] = i;
	}
	patterns[pattern_num++] = pattern;
	REP(i, k - 1) {
		REP(j, 4) {
			REP(k, 4) {
				int new_pattern[4];
				REP(l, 4) {
					new_pattern[l] = patterns[pattern_num - 1][l];
				}
				new_pattern[j] = k;
				patterns[pattern_num++] = new_pattern;
			}
		}
	}

	bool found = false;
	REP(i, pattern_num) {
		int r = a, g = b, b_ = c;
		REP(j, k) {
			if patterns[i][j] == 0 {
				continue;
			} else if patterns[i][j] == 1 {
				r *= 2;
			} else if patterns[i][j] == 2 {
				g *= 2;
			} else if patterns[i][j] == 3 {
				b_ *= 2;
			}
		}
		if (g > r && b_ > g) {
			printf("Yes\n");
			found = true;
			break;
		}
	}
	if (!found) {
		printf("No\n");
	}

	return 0;
}

