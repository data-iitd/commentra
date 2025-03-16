#include <iostream>
using namespace std;
int main ( ) {
    int li [ ] = { 0 }, ind = 0, i, p, q, count, x ;
    for ( i = 1 ; i <= 371 ; i++ ) {
        p = i, q = i ;
        count = 0 ;
        while ( p!= 0 ) {
            p /= 10 ;
            count++ ;
        }
        if ( count == 1 ) {
            li [ ind++ ] = i ;
        }
        if ( count == 2 ) {
            while ( q!= 0 ) {
                x = q % 10 ;
                q /= 10 ;
                li [ ind++ ] = x ;
            }
            ind -= 2 ;
            while ( ind >= 0 ) {
                cout << li [ ind-- ] ;
            }
            cout << endl ;
        }
        if ( count == 3 ) {
            while ( q!= 0 ) {
                x = q % 10 ;
                q /= 10 ;
                li [ ind++ ] = x ;
            }
            ind -= 3 ;
            while ( ind >= 0 ) {
                cout << li [ ind-- ] ;
            }
            cout << endl ;
        }
    }
    return 0 ;
}
