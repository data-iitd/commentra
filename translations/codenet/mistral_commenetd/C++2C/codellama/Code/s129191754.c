
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <float.h>
#include <time.h>
#include <assert.h>

#define REP(i,n) for(int i=0;i<n;i++) // Define a macro REP for repetition
#define all(x) (x).begin(),(x).end() // Define a macro all for getting the begin and end iterators of a container
#define mp make_pair // Define a macro mp for making a pair
#define pb push_back // Define a macro pb for pushing an element to the back of a container
#define eb emplace_back // Define a macro eb for emplacing an element to the back of a container

typedef long long ll; // Define a new type alias for long long

int main(void){ // The main function
    // Tie the cin object to cout to improve performance
    // Disable synchronization between cin, cout, and the standard input/output buffers
    // Read the number of elements in the vector
    int n;
    scanf("%d",&n);

    // Initialize a vector of size n with default-constructed elements
    int *a = (int *)malloc(n*sizeof(int));

    // Read the elements of the vector
    REP(i,n) scanf("%d",&a[i]);

    // Sort the vector in ascending order
    qsort(a,n,sizeof(int),cmp);

    // Check if there are any consecutive elements in the sorted vector
    REP(i,n-1){
        // If there are consecutive elements, print "NO" and exit the program
        if(a[i] == a[i+1]){
            printf("NO\n");
            return 0;
        }
    }

    // If no consecutive elements were found, print "YES"
    printf("YES\n");

    return 0; // Indicate successful termination of the program
}

int cmp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

