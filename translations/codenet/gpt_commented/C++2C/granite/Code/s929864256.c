
#include <stdio.h>    // Include the input-output stream library
#include <stdlib.h>   // Include the standard library (not used in this code)
#include <algorithm>  // Include the algorithm library for max function
#include <vector>     // Include the vector library (not used in this code)
#include <map>        // Include the map library (not used in this code)
#include <set>        // Include the set library (not used in this code)
#include <string.h>   // Include the string library (not used in this code)
#include <string>     // Include the string library (not used in this code)
#include <math.h>     // Include the math library (not used in this code)
#include <queue>      // Include the queue library (not used in this code)
#include <list>       // Include the list library (not used in this code)
#include <time.h>     // Include the time library (not used in this code)
#include <assert.h>    // Include the assert library (not used in this code)
#include <ctype.h>     // Include the ctype library (not used in this code)
#include <float.h>     // Include the float library (not used in this code)
#include <limits.h>    // Include the limits library (not used in this code)
#include <locale.h>    // Include the locale library (not used in this code)
#include <stdarg.h>    // Include the stdarg library (not used in this code)
#include <stddef.h>    // Include the stddef library (not used in this code)
#include <stdint.h>    // Include the stdint library (not used in this code)
#include <stdio.h>     // Include the stdio library (not used in this code)
#include <stdlib.h>    // Include the stdlib library (not used in this code)
#include <uchar.h>     // Include the uchar library (not used in this code)
#include <wchar.h>     // Include the wchar library (not used in this code)

int main() {
    int a, b; // Declare two integer variables a and b
    scanf("%d %d", &a, &b); // Read values for a and b from standard input

    // Calculate the maximum of the sum, difference, and product of a and b
    printf("%d\n", (a + b > a - b? (a + b > a * b? a + b : a * b) : (a - b > a * b? a - b : a * b))); // Output the maximum value

    return 0; // Return 0 to indicate successful execution
}


