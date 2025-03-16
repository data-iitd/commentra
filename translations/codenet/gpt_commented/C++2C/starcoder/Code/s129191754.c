#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

// Macro definitions for convenience
#define REP(i,n) for(int i=0;i<n;i++) // Repeat macro for loops
#define all(x) (x).begin(),(x).end() // Macro to get all elements of a container
#define mp make_pair // Macro to create a pair
#define pb push_back // Macro to add an element to the end of a vector
#define eb emplace_back // Macro to add an element to the end of a vector with construction

typedef long long ll; // Define long long type as ll

int main(void) {
    // Synchronize input/output for faster performance
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    
    // Read the number of elements
    int n;
    scanf("%d", &n);
    
    // Initialize a vector to store the elements and read them from input
    int a[n];
    REP(i, n) scanf("%d", &a[i]);
    
    // Sort the vector to facilitate duplicate checking
    qsort(a, n, sizeof(int), NULL);
    
    // Check for duplicates in the sorted vector
    REP(i, n - 1) {
        if (a[i] == a[i + 1]) {
            // If a duplicate is found, print "NO" and exit
            printf("NO\n");
            return 0;
        }
    }
    
    // If no duplicates are found, print "YES"
    printf("YES\n");
    
    return 0; // End of the program
}

