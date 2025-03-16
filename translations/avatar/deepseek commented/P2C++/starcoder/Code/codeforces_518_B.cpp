#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    string s, t ;
    cin >> s >> t ;
    map < char, int > freqs, freqt ;
    int yay, whoops = 0 ;
    for ( char letra : s ) {
        if ( letra in freqs ) freqs [ letra ] += 1 ;
        else freqs [ letra ] = 1 ;
    }
    for ( char letra : t ) {
        if ( letra in freqt ) freqt [ letra ] += 1 ;
        else freqt [ letra ] = 1 ;
    }
    for ( char letra : freqs ) {
        while ( freqs [ letra ] > 0 and letra in freqt and freqt [ letra ] > 0 ) {
            yay += 1 ;
            freqs [ letra ] -= 1 ;
            freqt [ letra ] -= 1 ;
        }
    }
    for ( char letra : freqs ) {
        while ( freqs [ letra ] > 0 ) {
            if ( letra >= 'a' and letra <= 'z' and letra.toupper ( ) in freqt and freqt [ letra.toupper ( ) ] > 0 ) {
                whoops += 1 ;
                freqs [ letra ] -= 1 ;
                freqt [ letra.toupper ( ) ] -= 1 ;
            }
            else if ( letra >= 'A' and letra <= 'Z' and letra.tolower ( ) in freqt and freqt [ letra.tolower ( ) ] > 0 ) {
                whoops += 1 ;
                freqs [ letra ] -= 1 ;
                freqt [ letra.tolower ( ) ] -= 1 ;
            }
            else break ;
        }
    }
    cout << yay << " " << whoops << endl ;
}

