#include <stdio.h>
#include <stdlib.h>

// Function to resolve the problem
void resolve( ) {

    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Initialize empty lists to store low and high values
    int low[n];
    int high[n];

    // Read low and high values for each test case and append to respective lists
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &low[i], &high[i]);
    }

    // Sort the low and high lists in ascending order
    qsort(low, n, sizeof(int), compare);
    qsort(high, n, sizeof(int), compare);

    // Check if the number of test cases is odd
    if (n % 2) {
        // If it is odd, print the difference between the middle low and middle high values
        printf("%d\n", high[(n+1)/2-1] - low[(n+1)/2-1] + 1);
    } else {
        // If it is even, calculate the average of middle low and middle high values
        int hh = (high[(n)/2-1] + high[(n)/2]) / 2;
        int ll = (low[(n)/2-1] + low[(n)/2]) / 2;

        // Print the result which is twice the difference between the averages
        printf("%d\n", (hh-ll)*2+1);
    }
}

// Function to compare two integers
int compare(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int main( ) {
    resolve( );
    return 0;
}

