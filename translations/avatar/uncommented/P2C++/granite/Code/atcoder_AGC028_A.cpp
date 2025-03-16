
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    vector <int> list_S ( N );
    vector <int> list_T ( M );
    for ( int i = 0; i < N; i++ ) {
        list_S [ i ] = int ( S [ i ] );
    }
    for ( int j = 0; j < M; j++ ) {
        list_T [ j ] = int ( T [ j ] );
    }
    vector <int> Number_i ( N );
    vector <int> Number_iMN ( N );
    for ( int i = 0; i < N; i++ ) {
        Number_i [ i ] = i;
        Number_iMN [ i ] = i * M / N;
    }
    vector <int> Number_j ( M );
    vector <int> Kaburi_j ( M );
    for ( int j = 0; j < M; j++ ) {
        Number_j [ j ] = j;
    }
    vector <int> Kaburi_i ( M );
    set_intersection ( Number_iMN.begin(), Number_iMN.end(), Number_j.begin(), Number_j.end(), Kaburi_j.begin() );
    for ( int j = 0; j < M; j++ ) {
        Kaburi_i [ j ] = int ( Number_i [ j ] * N / M );
    }
    int counter = 0;
    int Flag = 0;
    int Kaburi_Size = Kaburi_j.size();
    while ( counter <= Kaburi_Size - 1 ) {
        if ( list_S [ Kaburi_i [ counter ] ] == list_T [ Kaburi_j [ counter ] ] ) {
            pass;
        } else {
            Flag = 1;
            break;
        }
        counter++;
    }
    if ( Flag == 1 ) {
        cout << -1 << endl;
    } else {
        cout << int ( N * M / gcd ( N, M ) ) << endl;
    }
    return 0;
}
