
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
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
#include <ctype.h>
#include <float.h>
#include <time.h>
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
    // Read the value of N
    long N = atol(argv[1]);

    // Initialize min to 0 and find the minimum of the first five inputs
    long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0)
            min = atol(argv[i + 2]);
        else
            min = fmin(min, atol(argv[i + 2]));
    }

    // Calculate the result and print it
    printf("%ld\n", (long)ceil((double)N / min) + 4);

    return 0;
}

