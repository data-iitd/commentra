
#include <iostream>
#include <set>
#include <string>

int main ( ) {
    int n, m;
    std::cin >> n >> m;
    std::set < int > c;
    for ( int i = 0; i < n; i++ ) {
        std::string s;
        std::cin >> s;
        c.insert ( s.find ( 'S' ) - s.find ( 'G' ) );
    }
    std::cout << ( -1 if ( any_of ( c.begin ( ), c.end ( ), []( int a ) { return a < 0; } ) ) else c.size ( ) ) << std::endl;
    return 0;
}

