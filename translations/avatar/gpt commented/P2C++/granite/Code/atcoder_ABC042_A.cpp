
#include <iostream>
#include <tuple>
#include <algorithm>

int main() {
    // Read a line of input, split it into components, and convert each component to an integer, storing them in a tuple
    std::tuple<int, int, int> ABC;
    std::cin >> std::get<0>(ABC) >> std::get<1>(ABC) >> std::get<2>(ABC);

    // Check if the number 5 appears exactly twice in the tuple
    if (std::count(std::begin(ABC), std::end(ABC), 5) == 2) {
        // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
        if (std::accumulate(std::begin(ABC), std::end(ABC), 0) == 17) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        // If 5 does not appear exactly twice, print 'NO'
        std::cout << "NO" << std::endl;
    }

    return 0;
}

