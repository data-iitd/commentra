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
#include <stdint.h>
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
#include <stdint.h>

int main() {
	int N;
	scanf("%d", &N);

	int ans = 1;
	for (int i = 2; i <= N; i++) {
		if (is_prime((ll)i)) {
			int NN = N;
			int cnt = 0;
			while (NN) {
				cnt += NN/i;
				NN /= i;
			}
			ans *= cnt+1;
			ans %= mod;
		}
	}

	printf("%d\n", ans);
    return 0;
}

