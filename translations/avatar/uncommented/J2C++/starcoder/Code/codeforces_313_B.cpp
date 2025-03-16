#include <bits/stdc++.h>
using namespace std;

class Fast {
public:
    void sol ( std::istream & in, std::ostream & out ) {
        string s;
        in >> s;
        int cum [ s.length ( ) + 1 ] ;
        cum [ 0 ] = cum [ s.length ( ) ] = 0 ;
        for ( int i = 1 ; i < s.length ( ) ; i ++ ) {
            if ( s [ i ] == s [ i - 1 ] ) cum [ i ] = cum [ i - 1 ] + 1 ;
            else cum [ i ] = cum [ i - 1 ] ;
        }
        int q ;
        in >> q ;
        while ( q -- ) {
            int l, r ;
            in >> l >> r ;
            out << cum [ r ] - cum [ l - 1 ] << endl ;
        }
    }
} ;

int main ( ) {
    Fast f ;
    f.sol ( cin, cout ) ;
    return 0 ;
}

