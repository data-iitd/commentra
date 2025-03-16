#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
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
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    // Create a Scanner object to read input from the user
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the array in ascending order
    qsort(a, n, sizeof(int), compare);
    
    // If the largest number is 0, print 0 and exit
    if (a[n - 1] == 0) {
        printf("0\n");
        return 0;
    }
    
    // Initialize the answer variable
    int ans = 0;
    
    // Loop until the array is reduced to one element
    while (true) {
        // If only one element remains, set it as the answer and break the loop
        if (n == 1) {
            ans = a[0];
            break;
        }
        // Call the function to process the array and update it
        a = func(a, n);
        n = sizeof(a) / sizeof(a[0]);
    }
    
    // Print the final answer
    printf("%d\n", ans);
    return 0;
}

// Function to process the array and return a modified version
int *func(int *a, int n) {
    // Create a copy of the input array
    int *b = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    
    // Initialize a variable to store the minimum value
    int min = 0;
    
    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // If the current element is 0, remove it from the list
        if (b[i] == 0) {
            b[i] = INT_MAX;
        } else {
            // If min is not zero, update the current element
            if (min!= 0) {
                b[i] = b[i] % min;
                // If the updated element is 1, print 1 and exit
                if (b[i] == 1) {
                    printf("1\n");
                    return b;
                }
            } else {
                // Set min to the current element if min is still zero
                min = b[i];
            }
        }
    }
    
    // Sort the modified array before returning
    qsort(b, n, sizeof(int), compare);
    return b;
}

// Function to compare two integers
int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

