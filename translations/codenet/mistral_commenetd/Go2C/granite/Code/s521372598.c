
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // C code to solve the problem
    int n;
    scanf("%d", &n); // Read the number of elements in the array
    int *as = (int *)malloc(sizeof(int) * n); // Allocate memory for the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]); // Read the array elements
    }

    int *xs = (int *)malloc(sizeof(int) * n); // Allocate memory for the array xs
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1; // Assign the value xs[i] = a - i + 1
    }

    qsort(xs, n, sizeof(int), cmpfunc); // Sort the array xs in ascending order

    int b = xs[n / 2]; // Assign the middle element of the sorted array xs to variable b
    int ans = 0; // Initialize variable ans with 0
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b); // Calculate the absolute difference between each element and b
    }

    printf("%d\n", ans); // Print the answer

    free(as); // Free the memory allocated for the array as
    free(xs); // Free the memory allocated for the array xs

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    // Function to compare two integers for sorting
    return (*(int *)a - *(int *)b); // Return the difference between the two integers
}

int abs(int n) {
    // Function to calculate the absolute difference of a number
    if (n < 0) {
        // If the number is negative, return the negative number with the minus sign removed
        return -n;
    }
    // If the number is non-negative, return the number itself
    return n;
}

// -----------------------------------------

const int inf = 1 << 60; // Constant inf is set to 2^60
const int mod = 1000000007; // Constant mod is set to 1000000007

int getInt() {
    // Function to read an integer from standard input
    int ret;
    scanf("%d", &ret); // Read the next token
    return ret;
}

int *getIntSlice(int n) {
    // Function to read an array of n integers from standard input
    int *ret = (int *)malloc(sizeof(int) * n); // Allocate memory for the array
    for (int i = 0; i < n; i++) {
        ret[i] = getInt(); // Read each integer and assign it to the corresponding index in the array
    }
    return ret;
}

char *getString() {
    // Function to read a string from standard input
    char *ret = (char *)malloc(sizeof(char) * 1000001); // Allocate memory for the string
    fgets(ret, 1000001, stdin); // Read the string from standard input
    int len = strlen(ret); // Get the length of the string
    if (ret[len - 1] == '\n') {
        // If the last character of the string is a newline, remove it
        ret[len - 1] = '\0';
    }
    return ret;
}

// -----------------------------------------

