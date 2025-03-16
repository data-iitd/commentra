#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <complex.h>
#include <stdbool.h>
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
	int n;
	scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int s[n+1];
	for (int i = 0; i < n; i++) {
		s[i+1] = s[i] + a[i];
	}

	qsort(s, n+1, sizeof(int), compare);

	int ans = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == s[i+1]) {
			count++;
		} else if (count > 0) {
			ans += combi(count+1, 2);
			count = 0;
		}
	}
	if (count > 0) {
		ans += combi(count+1, 2);
	}

	printf("%d\n", ans);
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int combi(int n, int r) {
	int c = 1;
	for (int i = 1; i <= r; i++) {
		c = c * (n - i + 1) / i;
	}
	return c;
}

