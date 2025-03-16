#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define input functions
int* I() {
    int n, i, *arr;
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

char* IS() {
    char* s = (char*)malloc(100 * sizeof(char));
    scanf("%s", s);
    return s;
}

int IN() {
    int n;
    scanf("%d", &n);
    return n;
}

float IF() {
    float n;
    scanf("%f", &n);
    return n;
}

// Read the number of elements
int n = IN();

// Read the list of elements
int* l = I();

// Initialize variables
int f = 1;  // Flag variable
int c = 0;  // Counter variable

// Sort the list
qsort(l, n, sizeof(int), compare);

// Iterate through the list to find the maximum number of unique elements
for (int i = 0; i < n; i++) {
    if (l[i] > c) {
        c += 1;  // Increment the counter if the current element is greater than the counter
    }
}

// Print the result
printf("%d\n", c + 1);  // Print the maximum number of unique elements

// Free memory
free(l);

// End of code
