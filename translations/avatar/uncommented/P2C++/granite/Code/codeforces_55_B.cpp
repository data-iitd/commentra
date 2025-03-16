
#include <bits/stdc++.h>
using namespace std;

void rememberTheNumber ( vector < long long int > & nums, int i, vector < char > & operations, vector < long long int > & ans ) {
    if ( i >= 3 ) {
        return;
    }
    for ( int j = 0 ; j < 4 ; j ++ ) {
        for ( int k = j + 1 ; k < 4 ; k ++ ) {
            if ( nums [ j ]!= - 1 && nums [ k ]!= - 1 ) {
                long long int s = nums [ j ] ;
                nums [ j ] = - 1 ;
                long long int t = nums [ k ] ;
                if ( operations [ i ] == '+' ) {
                    nums [ k ] = s + t ;
                }
                else if ( operations [ i ] == '*' ) {
                    nums [ k ] = s * t ;
                }
                if ( i == 2 && nums [ k ] < ans [ 0 ] ) {
                    ans [ 0 ] = nums [ k ] ;
                }
                rememberTheNumber ( nums, i + 1, operations, ans ) ;
                nums [ j ] = s ;
                nums [ k ] = t ;
            }
        }
    }
}

int main ( ) {
    vector < long long int > nums ;
    string temp ;
    getline ( cin, temp ) ;
    stringstream ss ( temp ) ;
    long long int num ;
    while ( ss >> num ) {
        nums. push_back ( num ) ;
    }
    vector < char > operations ;
    getline ( cin, temp ) ;
    ss. clear ( ) ;
    ss. str ( temp ) ;
    char operation ;
    while ( ss >> operation ) {
        operations. push_back ( operation ) ;
    }
    vector < long long int > ans ( 1, 100000000000000000000000000 ) ;
    rememberTheNumber ( nums, 0, operations, ans ) ;
    cout << ans [ 0 ] << endl ;
    return 0 ;
}

