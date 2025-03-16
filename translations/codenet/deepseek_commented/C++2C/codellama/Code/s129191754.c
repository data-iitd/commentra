#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <assert.h>

#define REP(i,n) for(int i=0;i<n;i++) // Define a macro for loop operations
#define all(x) (x).begin(),(x).end() // Define a macro for accessing all elements of a container
#define mp make_pair // Define a macro for creating pairs
#define pb push_back // Define a macro for adding elements to a vector
#define eb emplace_back // Define a macro for adding elements to a vector in a more efficient way

typedef long long ll; // Define a type alias for long long
using namespace std; // Use the standard namespace

int main(void){
    cin.tie(0); // Optimize cin for speed
    ios::sync_with_stdio(false); // Disable synchronization between cin and stdout for faster I/O
    // cout << fixed << setprecision(20); // Uncomment to set precision for floating-point output
    int n;scanf("%d",&n); // Read an integer n
    vector<int> a(n);REP(i,n)scanf("%d",&a[i]); // Read n integers into a vector a
    sort(all(a)); // Sort the vector a
    REP(i,n-1){ // Iterate through the sorted vector to check for duplicates
        if(a[i] == a[i+1]){
            printf("NO\n"); // If duplicates are found, print "NO" and exit
            return 0;
        }
    }
    printf("YES\n"); // If no duplicates are found, print "YES"
        
    return 0; // Return 0 to indicate successful execution
}

