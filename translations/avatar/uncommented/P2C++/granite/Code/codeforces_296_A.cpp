
#include <iostream>
#include <string>
#include <set>

int main ( ) {
    int n;
    std::cin >> n;
    std::string m;
    std::cin >> m;
    std::set<char> s;
    for ( auto c : m ) {
        s.insert ( c );
    }
    bool possible = true;
    for ( auto c : s ) {
        if ( m.count ( c ) >= n / 2 + 1 ) {
            possible = false;
            break;
        }
    }
    std::cout << ( possible? "YES" : "NO" ) << std::endl;
    return 0;
}

