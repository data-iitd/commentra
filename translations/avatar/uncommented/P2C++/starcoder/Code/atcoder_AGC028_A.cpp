#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main ( ) {
    int N, M ;
    cin >> N >> M ;
    string S, T ;
    cin >> S >> T ;
    vector < int > Number_i ( N ), Number_iMN ( N ), Number_j ( M ), Kaburi_i ( N ), Kaburi_j ( M ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        Number_i [ i ] = i ;
    }
    for ( int i = 0 ; i < N ; i ++ ) {
        Number_iMN [ i ] = i * M / N ;
    }
    for ( int j = 0 ; j < M ; j ++ ) {
        Number_j [ j ] = j ;
    }
    sort ( Number_iMN.begin ( ), Number_iMN.end ( ) ) ;
    sort ( Number_j.begin ( ), Number_j.end ( ) ) ;
    set < int > Kaburi_j_set ( Number_iMN.begin ( ), Number_iMN.end ( ) ) ;
    set < int > Kaburi_i_set ( Number_j.begin ( ), Number_j.end ( ) ) ;
    Kaburi_j_set.erase ( Kaburi_j_set.find ( 0 ) ) ;
    Kaburi_i_set.erase ( Kaburi_i_set.find ( 0 ) ) ;
    int counter = 0, Flag = 0, Kaburi_Size = Kaburi_j_set.size ( ) ;
    while ( counter <= Kaburi_Size - 1 ) {
        if ( S [ Kaburi_i_set.find ( Kaburi_i [ counter ] ) ]!= T [ Kaburi_j_set.find ( Kaburi_j [ counter ] ) ] ) {
            Flag = 1 ;
            break ;
        }
        counter ++ ;
    }
    if ( Flag == 1 ) {
        cout << - 1 << endl ;
    } else {
        cout << N * M / gcd ( N, M ) << endl ;
    }
    return 0 ;
}
