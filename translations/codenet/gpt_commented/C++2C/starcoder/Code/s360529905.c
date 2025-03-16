#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
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
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
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

int main(void)
{
    // Declare pointers for the arrays and variables for loop index and size
    int *a, *b, i, N;
    int frontHalf, backHalf;

    // Read the number of elements
    scanf("%d", &N);

    // Dynamically allocate memory for two arrays of size N
    a = (int *)malloc(N * sizeof(int));
    b = (int *)malloc(N * sizeof(int));

    // Read elements into array 'a' and copy them to array 'b'
    for(i = 0; i < N; i++)
    {
        scanf("%d", a + i); // Read element into array 'a'
        b[i] = a[i];        // Copy element from 'a' to 'b'
    }

    // Sort the array 'b' to find the median values
    qsort(b, N, sizeof(int), compare);

    // Determine the two middle values (for even-sized arrays)
    frontHalf = b[N / 2 - 1]; // Value just before the median
    backHalf = b[N / 2];      // Median value

    // Free the memory allocated for array 'b'
    free(b);

    // Output the appropriate value based on the original array 'a'
    for(i = 0; i < N; i++)
    {
        // If the current element is less than the backHalf (median), print backHalf
        if(a[i] < backHalf)
            printf("%d\n", backHalf);
        // Otherwise, print frontHalf
        else
            printf("%d\n", frontHalf);
    }

    // Free the memory allocated for array 'a'
    free(a);

    return 0; // Indicate successful completion of the program
}

