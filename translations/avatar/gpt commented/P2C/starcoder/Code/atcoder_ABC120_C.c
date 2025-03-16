#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio_ext.h>
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
#include <wchar.h>
#include <wctype.h>

int main() {
    char s[1000000];
    scanf("%s", s);
    int a[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        a[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += a[i] / 2;
    }
    printf("%d\n", ans);
    return 0;
}

