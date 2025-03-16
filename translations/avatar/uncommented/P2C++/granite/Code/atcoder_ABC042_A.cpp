
#include <iostream>
#include <tuple>
#include <algorithm>

int main ( ) {
    auto ABC = std::tuple < int, int, int > ( );
    std::cin >> std::get < 0 > ( ABC ) >> std::get < 1 > ( ABC ) >> std::get < 2 > ( ABC );
    if ( std::count ( ABC, ABC + 3, 5 ) == 2 ) {
        if ( std::accumulate ( ABC, ABC + 3, 0 ) == 17 ) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
