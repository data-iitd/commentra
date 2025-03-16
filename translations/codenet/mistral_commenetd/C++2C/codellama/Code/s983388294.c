
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#pragma warning(disable:4996) 

typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

// Function to read an integer from the standard input
int main(int argc, char* argv[])
{
    // Initialize variables
    int n;

    // Read the number of elements in the array from the standard input
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Allocate memory for the array and read its elements
    int* a = (int*)malloc(n*sizeof(int));
    int i;
    for(i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &a[i]);
    }

    // Initialize a counter to keep track of the current element in the array
    int curr = 0;

    // Iterate through the array and increment the counter whenever the current element is one more than the previous one
    for(i=0; i<n; i++) {
        if(a[i]==curr+1) curr++;
    }

    // Check if the counter is greater than zero, and if so, print the number of elements that are not consecutive
    if(curr>0) {
        printf("The array has %d non-consecutive elements.\n", n-curr);
    }

    // If the counter is zero, print -1 to indicate that all elements are not consecutive
    else {
        printf("-1\n");
    }

    // Free the memory allocated for the array
    free(a);

    return 0;
}

