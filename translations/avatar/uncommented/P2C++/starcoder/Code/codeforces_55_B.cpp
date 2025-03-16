#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int nums [ 3 ], ans = 10000000000000000000000000;
    string operations [ 3 ];
    for ( int i = 0 ; i < 3 ; i++ ) {
        cin >> nums [ i ] >> operations [ i ];
    }
    function < void ( int, int, string [ ], int & ) > rememberTheNumber = [ & ] ( int i, int j, string operations [ ], int & ans ) {
        if ( i >= 3 ) {
            return;
        }
        for ( int k = j ; k < 4 ; k++ ) {
            for ( int l = k + 1 ; l < 4 ; l++ ) {
                if ( nums [ k ]!= -1 && nums [ l ]!= -1 ) {
                    int s = nums [ k ];
                    nums [ k ] = -1;
                    int t = nums [ l ];
                    if ( operations [ i ] == "+" ) {
                        nums [ l ] = s + t;
                    }
                    else if ( operations [ i ] == "*" ) {
                        nums [ l ] = s * t;
                    }
                    if ( i == 2 && nums [ l ] < ans ) {
                        ans = nums [ l ];
                    }
                    rememberTheNumber ( i + 1, l, operations, ans );
                    nums [ k ] = s;
                    nums [ l ] = t;
                }
            }
        }
    };
    rememberTheNumber ( 0, 0, operations, ans );
    cout << ans << endl;
    return 0;
}
