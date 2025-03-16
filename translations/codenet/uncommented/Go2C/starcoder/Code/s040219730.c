
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, q;
	scanf("%d %d", &n, &q);

	int C[n];
	REP(i, n) {
		scanf("%d", &C[i]);
	}

	int P[500000 + 50];
	REP(i, 500000 + 50) {
		P[i] = -1;
	}

	struct Query {
		int idx, l, r;
	};

	struct Query Q[q];
	REP(i, q) {
		scanf("%d %d", &Q[i].l, &Q[i].r);
		Q[i].idx = i;
	}

	qsort(Q, q, sizeof(struct Query), [](const void *a, const void *b) {
		return ((struct Query *)a)->r < ((struct Query *)b)->r;
	});

	int k = 0;
	for (int i = 0; i < q; i++) {
		for (k = 0; k < Q[i].r; k++) {
			if (P[C[k]]!= -1) {
				P[C[k]]++;
			}
			P[C[k]] = k;
		}

		int ans = 0;
		for (int j = Q[i].l - 1; j < Q[i].r; j++) {
			ans += P[C[j]] - j;
		}
		printf("%d\n", ans);
	}

	return 0;
}

