#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    int *nums = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    int bin = 0;
    int diff = 0;
    while (true) {
        int num = nums[bin];
        if (num == 0) {
            break;
        }
        int idx = bin;
        if ((bin % 2)!= (idx % 2)) {
            diff++;
        }
        bin++;
        bin %= 2;
    }
    int ans = (diff / 2);
    printf("%d\n", ans);
    return 0;
}

