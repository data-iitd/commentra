#include <stdio.h>
#include <stdlib.h>

// Define a function to read input efficiently
int* I() {
    int* buffer = (int*)malloc(1024 * sizeof(int));
    int* ptr = buffer;
    char ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
        *ptr++ = ch - '0';
    }
    *ptr = '\0';
    return buffer;
}

// Read the number of elements
int n;
scanf("%d", &n);

// Initialize variables to track the best candidate interval
int id = 0;
int l, r;
scanf("%d %d", &l, &r);

// Process each interval
for (int i = 1; i < n; i++) {
    int li, ri;
    scanf("%d %d", &li, &ri);
    // Check if the current interval completely covers the best candidate interval
    if (li <= l && r <= ri) {
        id = i;
    }
    // Check if the current interval overlaps with the best candidate interval
    else if (li < l || r < ri) {
        id = n;
    }
    // Update the boundaries of the best candidate interval
    l = (l < li) ? l : li;
    r = (r > ri) ? r : ri;
}

// Output the result
printf("%d\n", (id == n) ? -1 : id + 1);

