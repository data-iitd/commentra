
#include <iostream>
#include <cstdlib>

using namespace std ;

int main ( ) {
    int n, levels, level2, level3, count = 0 ;
    int sum = 0, sum2 = 0, sum3 = 0 ;
    int *arr, *arr2, *arr3 ;

    cin >> n >> levels ;

    arr = new int [ levels ] ;

    for ( int i = 0 ; i < levels ; i ++ ) {
        cin >> arr [ i ] ;
    }

    cin >> level2 ;

    level3 = levels + level2 ;

    arr2 = new int [ level3 ] ;

    for ( int i = 0 ; i < arr.length ; i ++ ) {
        arr2 [ i ] = arr [ i ] ;
    }

    for ( int i = arr.length ; i < level3 ; i ++ ) {
        cin >> arr2 [ i ] ;
    }

    arr3 = new int [ n ] ;

    for ( int i = 0 ; i < n ; i ++ ) {
        arr3 [ i ] = ++ j ;
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int x = 0 ; x < arr2.length ; x ++ ) {
            if ( arr3 [ i ] == arr2 [ x ] ) {
                count ++ ;
                break ;
            }
        }
    }

    if ( count == n ) {
        cout << "I become the guy." << endl ;
    } else {
        cout << "Oh, my keyboard!" << endl ;
    }

    delete [] arr ;
    delete [] arr2 ;
    delete [] arr3 ;

    return 0 ;
}

