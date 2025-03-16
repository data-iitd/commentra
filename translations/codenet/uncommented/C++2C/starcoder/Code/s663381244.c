#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main() {
	int money;
	while(scanf("%d", &money) == 1) {
		if(money == 0)
			break;

		int sum = 0;
		int num[4];
		for(int i = 0; i < 4; ++i) {
			scanf("%d", &num[i]);
			sum += num[i] * (10 << (i * 2));
		}

		int change = sum - money;
		for(int i = 3; i >= 0; --i) {
			if(change / (10 << (i * 2))) {
				num[i] = num[i] - change / (10 << (i * 2));
				change %= (10 << (i * 2));
			}
		}

		for(int i = 0; i < 4; ++i)
			if(num[i] > 0)
				printf("%d %d\n", 10 << (i * 2), num[i]);
		printf("\n");
	}

	return EXIT_SUCCESS;
}

