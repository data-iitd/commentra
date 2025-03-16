
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n;
    cin >> n;
    vector < int > nums ( n );
    for ( int i = 0 ; i < n ; i ++ )
        cin >> nums [ i ];
    string s;
    cin >> s;
    vector < string > operations ( s.size ( ) );
    for ( int i = 0 ; i < s.size ( ) ; i ++ )
        operations [ i ] = s [ i ];
    vector < int > ans ( 1, 10000000000000000000000000 );
    rememberTheNumber ( nums, 0, operations, ans );
    cout << ans [ 0 ] << endl;
    return 0;
}

void rememberTheNumber ( vector < int > & nums, int i, vector < string > & operations, vector < int > & ans ) {
    if ( i >= 3 )
        return;
    for ( int j = 0 ; j < 4 ; j ++ )
        for ( int k = j + 1 ; k < 4 ; k ++ )
            if ( nums [ j ]!= - 1 && nums [ k ]!= - 1 ) {
                int s = nums [ j ];
                nums [ j ] = - 1;
                int t = nums [ k ];
                if ( operations [ i ] == '+' )
                    nums [ k ] = s + t;
                else if ( operations [ i ] == '*' )
                    nums [ k ] = s * t;
                if ( i == 2 && nums [ k ] < ans [ 0 ] )
                    ans [ 0 ] = nums [ k ];
                rememberTheNumber ( nums, i + 1, operations, ans );
                nums [ j ] = s;
                nums [ k ] = t;
            }
}

