

#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, int, int> ABC;  // Declare a tuple ABC of three integers
    std::cin >> std::get<0>(ABC) >> std::get<1>(ABC) >> std::get<2>(ABC);  // Take input from user and store in tuple ABC

    // Check if the tuple contains exactly two 5s
    if (std::count(std::begin(ABC), std::end(ABC), 5) == 2) {
        // Check if the sum of the elements in ABC is 17
        if (std::accumulate(std::begin(ABC), std::end(ABC), 0) == 17) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

