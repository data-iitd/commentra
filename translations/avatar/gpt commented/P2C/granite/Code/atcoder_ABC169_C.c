
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    // Import necessary modules
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <time.h>
    #include <sys/time.h>
    #include <sys/resource.h>

    // Define a debug print function that only prints if running in a terminal environment
    #define dbg(...) if (isatty(fileno(stdout))) fprintf(stderr, __VA_ARGS__)

    // Define a function to read a single integer from input
    #define II() ({\
        register int __x; scanf("%d", &__x); __x;\
    })

    // Constants for calculations
    #define P 100000007  // A large prime number for modulo operations
    #define INF 100000001  // A large number representing infinity

    // Read two values from input: one as an integer and the other as a float in string format
    char sa[100000];
    char sb[100000];
    fgets(sa, 100000, stdin);
    fgets(sb, 100000, stdin);
    sa[strcspn(sa, "\n")] = 0;
    sb[strcspn(sb, "\n")] = 0;

    // Convert the first value to an integer
    int a = atoi(sa);

    // Convert the second value to an integer representing cents (by multiplying by 100)
    int b = (int)(atof(sb) * 100 + 0.1);

    // Calculate and print the product of a and b, divided by 100 to get the final result
    printf("%d\n", a * b / 100);

    // End of code
    return 0;
}

