

#include <bits/stdc++.h>  // Including necessary header files

using namespace std ;  // Using the'std' namespace

typedef long long ll ;  // Defining a new type 'll' for 64-bit integers

const int mod = 1e9 + 7 ;  // Defining a constant value for modulo arithmetic

const int DX [ ] = { - 1, 0, 1, 0 }, DY [ ] = { 0, - 1, 0, 1 } ;  // Defining the four directions for BFS/DFS

int n ;  // Number of elements in the array 'a'
ll k ;  // A given value
ll a [ ] ;  // The array to be processed

bool check ( ll x ) {  // A helper function to check if the condition is satisfied
    ll tot = 0 ;  // Initializing a variable to store the total number of elements that can be covered

    for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through all the elements in the array 'a'
        ll now = a [ i ] ;  // Reading the current element
        int l = 0, r = n ;  // Initializing the left and right indices for the binary search

        if ( now >= 0 ) {  // If the current element is non-negative
            while ( l < r ) {  // Performing binary search to find the index 'c' such that 'now * a[c]' is close to 'x'
                int c = ( l + r ) / 2 ;
                if ( now * a [ c ] < x ) l = c + 1 ;  // If 'now * a[c]' is smaller than 'x', update the left index
                else r = c ;  // Otherwise, update the right index
            }
            tot += l ;  // Adding the index 'l' to the total number of elements that can be covered
        } else {  // If the current element is negative
            while ( l < r ) {  // Performing binary search to find the index 'c' such that 'now * a[c]' is greater than or equal to 'x'
                int c = ( l + r ) / 2 ;
                if ( now * a [ c ] >= x ) l = c + 1 ;  // If 'now * a[c]' is greater than or equal to 'x', update the left index
                else r = c ;  // Otherwise, update the right index
            }
            tot += ( n - l ) ;  // Adding the remaining elements to the total number of elements that can be covered
        }

        if ( ( ll ) a [ i ] * a [ i ] < x ) tot -- ;  // If the square of the current element is smaller than 'x', decrement the total number of elements that can be covered

        if ( tot / 2 < k ) return true ;  // If the total number of elements that can be covered is less than 'k', return true
    }

    return false ;  // Otherwise, return false
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;  // Disabling input synchronization with CRT functions
    cin.tie ( NULL ) ;  // Setting the input stream to null

    cin >> n >> k ;  // Reading the number of elements in the array 'a' and the given value 'k'
    a = new ll [ n ] ;  // Allocating memory for the array 'a'

    for ( int i = 0 ; i < n ; i ++ ) {  // Reading the elements of the array 'a'
        cin >> a [ i ] ;
    }

    sort ( a, a + n ) ;  // Sorting the elements of the array 'a' in ascending order

    ll INF = ( ll ) ( 1e18 ) + 1 ;  // Defining a large constant value for the upper bound of the binary search range
    ll l = - INF ;  // Initializing the lower bound of the binary search range to a very large negative value
    ll r = INF ;  // Initializing the upper bound of the binary search range to a very large positive value

    while ( l + 1 < r ) {  // Performing binary search to find the answer
        ll c = ( l + r ) / 2 ;
        if ( check ( c ) ) l = c ;  // If the condition is satisfied, update the lower bound
        else r = c ;  // Otherwise, update the upper bound
    }

    cout << l << endl ;  // Printing the answer

    return 0 ;  // Returning 0 to indicate successful execution
}

