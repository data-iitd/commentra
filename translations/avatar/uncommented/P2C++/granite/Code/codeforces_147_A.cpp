
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ( ) {
    string s;
    cin >> s;
    vector < char > res;
    vector < char > punctuation = { ',', '.', '!', '?' };
    for ( int i = 0; i < s.length ( ); i ++ ) {
        if ( i >= 1 ) {
            if ( s [ i ] =='' ) {
                if ( res [ res.size ( ) - 1 ]!='' ) {
                    res.push_back ( s [ i ] );
                } else {
                    continue;
                }
            } else {
                if ( find ( punctuation.begin ( ), punctuation.end ( ), s [ i ] )!= punctuation.end ( ) ) {
                    if ( res [ res.size ( ) - 1 ] =='' ) {
                        res.pop_back ( );
                    }
                    res.push_back ( s [ i ] );
                    res.push_back ('' );
                } else {
                    res.push_back ( s [ i ] );
                }
            }
        } else {
            if ( s [ i ] =='' ) {
                continue;
            }
            if ( find ( punctuation.begin ( ), punctuation.end ( ), s [ i ] )!= punctuation.end ( ) ) {
                continue;
            } else {
                res.push_back ( s [ i ] );
            }
        }
    }
    for ( int i = 0; i < res.size ( ); i ++ ) {
        cout << res [ i ];
    }
    cout << endl;
    return 0;
}
