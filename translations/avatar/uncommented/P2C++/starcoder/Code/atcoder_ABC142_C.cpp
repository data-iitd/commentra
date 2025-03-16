#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    vector < pair < int, int > > A;
    for ( int i = 0 ; i < N ; i++ ) {
        int x;
        cin >> x;
        A.push_back ( make_pair ( i + 1, x ) );
    }
    sort ( A.begin ( ), A.end ( ), []( pair < int, int > a, pair < int, int > b ) { return a.second < b.second; } );
    for ( int i = 0 ; i < N - 1 ; i++ ) {
        cout << A[i].first << " ";
    }
    cout << A[N - 1].first << endl;
    return 0;
}
