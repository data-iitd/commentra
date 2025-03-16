
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main ( ) {
    int n;
    scanf ( "%d", & n );
    map < int, int > w;
    for ( int i = 0 ; i < n ; i ++ ) {
        int x;
        scanf ( "%d", & x );
        w [ x ] ++;
    }
    long long c = 0;
    for ( auto i : w ) {
        if ( i. first == 0 ) {
            c += 1LL * i. second * ( i. second - 1 );
        } else {
            if ( w. find ( - i. first )!= w. end ( ) ) {
                c += 1LL * i. second * w [ - i. first ];
            }
        }
    }
    printf ( "%lld\n", c / 2 );
    return 0;
}

