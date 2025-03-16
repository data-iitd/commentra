#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
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
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
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

int main(int argc, char **argv) {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    int leftl[N];
    int rightl[N];
    int index = 0;
    while (index < N) {
        while (!que.isEmpty() && a[que.peek()] > a[index]) {
            int ind = que.poll();
            rightl[ind] = index - ind - 1;
        }
        que.push(index++);
    }
    while (!que.isEmpty()) {
        int ind = que.poll();
        rightl[ind] = N - ind - 1;
    }
    index = N - 1;
    while (index >= 0) {
        while (!que.isEmpty() && a[que.peek()] > a[index]) {
            int ind = que.poll();
            leftl[ind] = ind - index - 1;
        }
        que.push(index--);
    }
    while (!que.isEmpty()) {
        int ind = que.poll();
        leftl[ind] = ind - index - 1;
    }
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    printf("%ld", ans);
    return 0;
}

