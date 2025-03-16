
#include <iostream>
#include <string>
#include <vector>

int main ( ) {
    int n, k ;
    std::cin >> n >> k ;
    std::string v ;
    std::cin >> v ;
    std::vector < std::string > d = { "LEFT", "RIGHT" } ;
    bool f = k - 1 < n - k ;
    int m = std::min ( k - 1, n - k ) ;
    std::vector < std::string > a ;
    for ( int i = 0 ; i < m ; i ++ ) {
        a.push_back ( d [! f ] ) ;
    }
    for ( char i : v [ : : -1 + 2 * f ] ) {
        a.push_back ( "PRINT " + i ) ;
        a.push_back ( d [ f ] ) ;
    }
    for ( int i = 0 ; i < a.size ( ) - 1 ; i ++ ) {
        std::cout << a [ i ] << std::endl ;
    }
    return 0 ;
}

