
#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library
#include <string.h> // Including the string library
#include <math.h> // Including the math library
#include <time.h> // Including the time library
#include <stdarg.h> // Including the variable argument list library
#include <assert.h> // Including the assert library
#include <ctype.h> // Including the character type library
#include <errno.h> // Including the error number library
#include <float.h> // Including the floating-point library
#include <inttypes.h> // Including the integer types library
#include <limits.h> // Including the limits library
#include <locale.h> // Including the locale library
#include <setjmp.h> // Including the setjmp/longjmp library
#include <signal.h> // Including the signal library
#include <stdbool.h> // Including the standard boolean library
#include <stddef.h> // Including the size and NULL library
#include <stdint.h> // Including thestdint library
#include <stdio.h> // Including the standard I/O library
#include <stdlib.h> // Including the standard library
#include <string.h> // Including the string library
#include <uchar.h> // Including the universal character set library
#include <wchar.h> // Including the wide character library
#include <wctype.h> // Including the wide character type library

int main() { // Defining the main function
    int n, s, max = 0, f, t; // Declaring and initializing variables
    scanf("%d %d", &n, &s); // Reading the first and second integers from the standard input
    while (n-- > 0) { // Looping n times
        scanf("%d %d", &f, &t); // Reading the first and second values in the loop
        if (max < f + t) { // Checking if the sum of f and t is greater than the current max
            max = f + t; // Updating max if the condition is true
        }
    }
    printf("%d\n", max > s? max : s); // Printing the maximum of max and s
    return 0; // Returning 0 to indicate successful execution
}

