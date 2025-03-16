
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n ;
    cin >> n ;
    int arr [ n ] ;
    for ( int i = 0 ; i < n ; i ++ )
        cin >> arr [ i ] ;
    Task tsk = Task ( ) ;
    cout << tsk.solve ( arr ) << endl ;
    return 0 ;
}

class Task {
public:
    int solve ( int [ ] arr ) {
        int n = arr.length ;
        int sorted [ n ] = { } ;
        for ( int i = 0 ; i < n ; i ++ )
            sorted [ i ] = arr [ i ] ;
        sort ( sorted, sorted + n ) ;
        
        long total = ( long ) n * ( n + 1 ) / 2 ;
        int l = 0, r = n - 1 ;
        
        // Implement binary search to find the median
        while ( l < r ) {
            int mid = l + ( r - l ) / 2 ;
            int target = sorted [ mid ] ;
            int cur = 0 ;
            long cnt = 0 ;
            long bit [ 2 * n + 2 ] = { } ;
            
            for ( int x = n + 1 ; x < bit.length ; x += x & - x )
                bit [ x ] ++ ; // Initialize the binary indexed tree
            
            for ( int i = 0 ; i < n ; i ++ ) {
                cur += arr [ i ] <= target? 1 : - 1 ;
                for ( int x = cur + n + 1 ; x < bit.length ; x += x & - x )
                    bit [ x ] ++ ; // Update the binary indexed tree
                for ( int x = cur + n ; x > 0 ; x -= x & - x )
                    cnt += bit [ x ] ; // Calculate the count of elements less than or equal to the target
            }
            
            if ( cnt >= total / 2 + 1 )
                r = mid ; // Adjust the search range if the count is sufficient
            else
                l = mid + 1 ;
        }
        
        return sorted [ l ] ; // Return the median value
    }
}

