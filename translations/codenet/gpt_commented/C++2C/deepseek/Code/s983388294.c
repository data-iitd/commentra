#include <stdio.h>
#include <stdlib.h>

// Define long long type for convenience
typedef long long ll;

// Macros for minimum and maximum
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))

// Constants for large values
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007; // Modulo constant for large number operations
// const long long MOD = 998244353; // Alternative modulo constant (commented out)

int main(int argc, char* argv[])
{
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize an array to store the input elements
    int* a = (int*)malloc(n * sizeof(int));
    int i;

    // Read n integers into the array
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize a counter for the current expected number
    int curr=0;

    // Iterate through the array to find the longest prefix of consecutive integers starting from 1
    for(i=0; i<n; i++) {
        if(a[i]==curr+1) curr++; // Increment curr if the current element matches the expected value
    }

    // Check if any consecutive integers were found
    if(curr>0) {
        // Print the number of elements not in the consecutive sequence
        printf("%d\n", n-curr);
    }
    else {
        // If no consecutive integers were found, print -1
        printf("-1\n");
    }

    // Free the allocated memory
    free(a);

    return 0; // Return success
}
