#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
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
#include <float.h>
#include <time.h>
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

int main() {

    int N, M;
    scanf("%d %d", &N, &M); // Reading two integers, N and M.

    int L[100000]; // Initializing a vector L with a size of 100,000.
    int l;
    for (int i = 0; i < N; i++) {
        scanf("%d", &l); // Reading N integers and populating the vector L.
        L[i] = l;
    }

    qsort(L, N, sizeof(int), cmpfunc); // Sorting the vector L in ascending order.

    for (int i = 0; i < M; i++) { // Performing M operations.
        int max_L = L[N-1]; // Finding the largest element in the list.
        if (max_L == 0) {
            break; // If the largest element is 0, break the loop.
        }

        max_L /= 2; // Halving the largest element.
        int j;
        for (j = 0; j < N; j++) {
            if (L[j] >= max_L) {
                break;
            }
        }
        L[j] = max_L; // Inserting the halved value back into the list.
        N--; // Removing the largest element from the list.
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    printf("%lld\n", ans); // Printing the result.

}

