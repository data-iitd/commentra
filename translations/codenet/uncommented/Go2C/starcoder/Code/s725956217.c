#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <float.h>
#include <complex.h>
#include <tgmath.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <stdnoreturn.h>
#include <threads.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	struct shop {
		int a, b;
	} *s = malloc(sizeof(struct shop) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &s[i].a, &s[i].b);
	}
	qsort(s, N, sizeof(struct shop), (int (*)(const void *, const void *))shop_cmp);
	int total = 0;
	for (int i = 0; i < N; i++) {
		int n = min(s[i].b, M);
		total += n * s[i].a;
		M -= n;
		if (M == 0) {
			break;
		}
	}
	printf("%d", total);
}

int shop_cmp(struct shop *a, struct shop *b) {
	if (a->a < b->a) {
		return -1;
	}
	if (a->a > b->a) {
		return 1;
	}
	return 0;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

