
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <assert.h>
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
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <assert.h>
#include <complex.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <stdnoreturn.h>
#include <tgmath.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

// Create a Scanner object to read input from the console
int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    // Check if the input is 1, if so, print the only integer and exit the program
    if (n == 1) {
        int x;
        scanf("%d", &x);
        printf("%d\n", x);
        return 0;
    }

    // Initialize an ArrayList to store the integers
    int *a = malloc(n * sizeof(int));

    // Read the rest of the integers and add them to the ArrayList
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the ArrayList in ascending order
    qsort(a, n, sizeof(int), compare);

    // Check if the last integer in the ArrayList is 0, if so, print 0 and exit the program
    if (a[n - 1] == 0) {
        printf("%d\n", 0);
        return 0;
    }

    // Initialize the answer variable
    int ans = 0;

    // Use a while loop to keep applying the function to the ArrayList until it contains only one element
    while (true) {
        if (n == 1) {
            ans = a[0]; // Assign the only remaining integer to the answer variable
            break; // Exit the loop
        }
        a = func(a, n); // Apply the function to the ArrayList and assign the result back to it
        n = n - 1;
    }

    // Print the answer
    printf("%d\n", ans);
    return 0;
}

// Define a private static function to apply the logic to the ArrayList
int *func(int *A, int n) {
    int *a = A; // Create a copy of the ArrayList to modify it without affecting the original one
    int min = 0;

    // Iterate through the ArrayList and apply the logic to each integer
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) { // If the current integer is 0, remove it and decrease the index of the for loop
            a[i] = a[i + 1];
            a[i + 1] = 0;
            n--;
            i--;
        } else {
            if (min!= 0) { // If there is already a minimum value, apply the modulo operation and check if the result is 1
                a[i] = a[i] % min;
                if (a[i] == 1) { // If the result is 1, print 1 and exit the program
                    printf("%d\n", 1);
                    return 0;
                }
            } else { // If there is no minimum value yet, assign the current integer as the minimum value
                min = a[i];
            }
        }
    }

    // Sort the ArrayList in ascending order and return it
    qsort(a, n, sizeof(int), compare);
    return a;
}

// Define a private static function to compare two integers
int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

// 