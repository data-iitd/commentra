#include <iostream>
#include <map>

using namespace std ;

int main ( ) {
    int n ;
    cin >> n ;

    map < int , int > map ;

    while ( n -- > 0 ) {
        int num ;
        cin >> num ;

        if ( map.find ( num ) == map.end ( ) ) {
            int val = map [ num ] ;
            map [ num ] ++ ;
        } else {
            int key = map.lower_bound ( num ) -> first ;
            int val = map [ key ] ;

            if ( val == 1 ) {
                map.erase ( key ) ;
            } else {
                map [ key ] -- ;
            }

            int val = map [ num ] ;
            map [ num ] ++ ;
        }
    }

    int ans = 0 ;

    for ( auto it = map.begin ( ) ; it != map.end ( ) ; it ++ ) {
        int key = it -> first ;
        int val = it -> second ;
        ans += val ;
    }

    cout << ans << endl ;

    return 0 ;
}

