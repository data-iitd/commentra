#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int number, bonus;
} problem;

int min(int a, int b) {
	if (a >= b) {
		return b;
	}
	return a;
}

int main() {
	int D, G;
	scanf("%d %d", &D, &G);
	problem *problems = (problem *) malloc(sizeof(problem) * D);
	for (int i = 0; i < D; i++) {
		scanf("%d", &problems[i].number);
		scanf("%d", &problems[i].bonus);
	}
	// printf("D %d G %d problems %p\n", D, G, problems);

	int ans = 10000;
	for (int bit = 0; bit < (1 << D); bit++) {
		int score = 0;
		int solved = 0;
		int ok = 0;
		for (int j = 0; j < D; j++) {
			if (bit & (1 << j)) {
				score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
				solved += problems[j].number;
			}
		}
		if (score < G) {
			int j;
			for (j = D - 1; j >= 0; j--) {
				if (bit & (1 << j)) {
					break;
				}
			}
			for (int k = 0; k < problems[j].number; k++) {
				score += (j + 1) * 100;
				solved++;
				if (score >= G) {
					ok = 1;
					break;
				}
			}
			if (!ok) {
				score += problems[j].bonus;
				if (score >= G) {
					ok = 1;
				}
			}
		} else {
			ok = 1;
		}
		if (ok) {
			ans = min(ans, solved);
		}
	}
	printf("%d\n", ans);
	return 0;
}

