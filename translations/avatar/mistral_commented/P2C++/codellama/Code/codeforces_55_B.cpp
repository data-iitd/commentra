
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void rememberTheNumber ( vector < int > nums , int i , vector < string > operations , vector < int > ans ) {
    if ( i >= 3 ) {
        return;
    }
    for ( int j = 0 ; j < 4 ; j++ ) {
        for ( int k = j + 1 ; k < 4 ; k++ ) {
            if ( nums [ j ] != - 1 and nums [ k ] != - 1 ) {
                int s = nums [ j ];
                nums [ j ] = - 1;
                int t = nums [ k ];
                if ( operations [ i ] == "+" ) {
                    nums [ k ] = s + t;
                } else if ( operations [ i ] == "*" ) {
                    nums [ k ] = s * t;
                }
                if ( i == 2 and nums [ k ] < ans [ 0 ] ) {
                    ans [ 0 ] = nums [ k ];
                }
                rememberTheNumber ( nums , i + 1 , operations , ans );
                nums [ j ] = s;
                nums [ k ] = t;
            }
        }
    }
}

int main () {
    vector < int > nums;
    int n;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        int x;
        cin >> x;
        nums.push_back ( x );
    }
    vector < string > operations;
    int m;
    cin >> m;
    for ( int i = 0 ; i < m ; i++ ) {
        string op;
        cin >> op;
        operations.push_back ( op );
    }
    vector < int > ans;
    ans.push_back ( 10000000000000000000000000 );
    rememberTheNumber ( nums , 0 , operations , ans );
    cout << ans [ 0 ] << endl;
    return 0;
}

