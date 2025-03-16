#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define necessary headers for input/output operations and utility methods

int main() {
    int a, b, c, d;
    
    // Read four integers from the input
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Check the values of a, b, c, and d and print the result based on the conditions
    if (c > b) {
        printf("0\n");
    } else if (a > d) {
        printf("0\n");
    } else if (a < c) {
        printf("%d\n", (b < d) ? (b - c) : (d - c));
    } else {
        int l[4];
        l[0] = a;
        l[1] = b;
        l[2] = c;
        l[3] = d;
        qsort(l, 4, sizeof(int), (int (*)(const void *, const void *))compare);
        printf("%d\n", l[2] - l[1]);
    }
    
    // Define a function for comparing integers for qsort
    int compare(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
    }
    
    return 0;
}

// <END-OF-CODE>