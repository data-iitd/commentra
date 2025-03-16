#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
int main(void) {
	int n, a[100], b[100], sum = 0;scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) {
		scanf("%d", &b[i]);
		if (a[i] - b[i] > 0) {
			sum += a[i] - b[i];
		}
	}
	printf("%d\n", sum);
}
