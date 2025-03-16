
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
    vector < int > Number_i ( N ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        Number_i [ i ] = i ;
    }
    vector < int > Number_iMN ( N ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        Number_iMN [ i ] = i * M / N ;
    }
    vector < int > Number_j ( M ) ;
    for ( int j = 0 ; j < M ; j ++ ) {
        Number_j [ j ] = j ;
    }
    vector < int > Kaburi_j ( set_intersection ( Number_iMN.begin ( ), Number_iMN.end ( ), Number_j.begin ( ), Number_j.end ( ), Number_iMN.begin ( ) ) ) ;
    vector < int > Kaburi_i ( ) ;
    for ( int j = 0 ; j < Kaburi_j.size ( ) ; j ++ ) {
        Kaburi_i.push_back ( int ( Kaburi_j [ j ] * N / M ) ) ;
    }
    int counter = 0, Flag = 0 ;
    while ( counter <= Kaburi_i.size ( ) - 1 ) {
        if ( S [ Kaburi_i [ counter ] ] == T [ Kaburi_j [ counter ] ] ) {
            pass ;
        }
        else {
            Flag = 1 ;
            break ;
        }
        counter ++ ;
    }
    if ( Flag == 1 ) {
        cout << - 1 << endl ;
    }
    else {
        cout << N * M / gcd ( N, M ) << endl ;
    }
    return 0 ;
}
