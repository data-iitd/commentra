#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <tgmath.h>
#include <wchar.h>
#include <wctype.h>

#define MAX_N 1000000

int main() {
    int n;
    scanf("%d", &n);
    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ok = n;
    int ng = 0;
    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(k, a, n)) {
            ok = k;
        } else {
            ng = k;
        }
    }
    printf("%d\n", ok);
    return 0;
}

bool isPossible(int k, int a[], int n) {
    int current = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= current) {
            if (k == 1) return false;
            while (s[p] >= k) {
                s[p]--;
                p--;
            }
            int p = a[i] - 1;
            while (true) {
                if (p < 0) return false;
                int sp = s[p] + 1;
                s[p] = sp;
                if (sp == k) {
                    s[p]--;
                    p--;
                } else {
                    break;
                }
            }
        }
        current = a[i];
    }
    return true;
}

