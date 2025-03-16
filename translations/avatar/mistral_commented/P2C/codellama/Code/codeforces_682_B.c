#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a list of integers from standard input
int *I(int n) {
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    return l;
}

// Function to read an integer from standard input
int IS() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read an integer from standard input and convert it to an integer
int IN() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a float from standard input
float IF() {
    float n;
    scanf("%f", &n);
    return n;
}

// Read the number of test cases 'n'
int n = IS();

// Read the list 'l' of length 'n' containing 'n' integers
int *l = I(n);

// Initialize variable 'f' to 1
int f = 1;

// Sort the list 'l' in ascending order
qsort(l, n, sizeof(int), compare);

// Initialize variable 'c' to 0
int c = 0;

// Iterate through the list 'l'
for (int i = 0; i < n; i++) {
    // If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
    if (l[i] > c) {
        c += 1;
    }
}

// Print the final result, which is the number of unique elements in the list 'l' plus 1
printf("%d\n", c + 1);

// Function to compare two integers
int compare(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

