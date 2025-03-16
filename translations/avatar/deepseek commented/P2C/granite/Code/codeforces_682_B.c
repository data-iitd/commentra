
#include <stdio.h>  // Include necessary header files
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <locale.h>
#include <setjmp.h>
#include <stdbool.h>

// Define input functions
#define I() ({ int a; scanf("%d", &a); a; })  // Read a single integer
#define IS() ({ char a[1000]; fgets(a, 1000, stdin); a[strlen(a) - 1] = '\0'; a; })  // Read a single string
#define IN() ({ int a; scanf("%d", &a); a; })  // Read a single integer
#define IF() ({ float a; scanf("%f", &a); a; })  // Read a single float

// Define output functions
#define O(x) printf("%d", x)  // Print a single integer
#define OS(x) printf("%s", x)  // Print a single string
#define ON(x) printf("%d", x)  // Print a single integer
#define OF(x) printf("%f", x)  // Print a single float

// Define other necessary functions and macros

// Read the number of elements
int n = IN();

// Read the list of elements
int l[n];
for (int i = 0; i < n; i++) {
    l[i] = IN();
}

// Sort the list
qsort(l, n, sizeof(int));

// Initialize variables
int f = 1;  // Flag variable
int c = 0;  // Counter variable

// Iterate through the list to find the maximum number of unique elements
for (int i = 0; i < n; i++) {
    if (l[i] > c) {
        c++;  // Increment the counter if the current element is greater than the counter
    }
}

// Print the result
O(c + 1);  // Print the maximum number of unique elements

// End of code
