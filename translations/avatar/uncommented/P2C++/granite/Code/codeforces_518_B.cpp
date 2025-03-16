
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    string s, t ;
    cin >> s >> t ;
    map < char, int > freqs ;
    map < char, int > freqt ;
    int yay = 0, whoops = 0 ;
    for ( char letra : s ) {
        if ( freqs.find ( letra )!= freqs.end ( ) ) {
            freqs [ letra ] += 1 ;
        } else {
            freqs [ letra ] = 1 ;
        }
    }
    for ( char letra : t ) {
        if ( freqt.find ( letra )!= freqt.end ( ) ) {
            freqt [ letra ] += 1 ;
        } else {
            freqt [ letra ] = 1 ;
        }
    }
    for ( char letra : freqs.keys ( ) ) {
        while ( freqs [ letra ] > 0 && letra in freqt && freqt [ letra ] > 0 ) {
            yay += 1 ;
            freqs [ letra ] -= 1 ;
            freqt [ letra ] -= 1 ;
        }
    }
    for ( char letra : freqs.keys ( ) ) {
        while ( freqs [ letra ] > 0 ) {
            if ( letra.islower ( ) && letra.upper ( ) in freqt.keys ( ) && freqt [ letra.upper ( ) ] > 0 ) {
                whoops += 1 ;
                freqs [ letra ] -= 1 ;
                freqt [ letra.upper ( ) ] -= 1 ;
            } else if ( letra.isupper ( ) && letra.lower ( ) in freqt.keys ( ) && freqt [ letra.lower ( ) ] > 0 ) {
                whoops += 1 ;
                freqs [ letra ] -= 1 ;
                freqt [ letra.lower ( ) ] -= 1 ;
            } else {
                break ;
            }
        }
    }
    cout << yay << " " << whoops << endl ;
    return 0 ;
}
