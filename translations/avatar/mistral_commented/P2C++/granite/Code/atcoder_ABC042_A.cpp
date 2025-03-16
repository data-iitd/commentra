
#include <iostream>
#include <tuple>
#include <algorithm>

int main() {
    // Define a tuple 'ABC' by applying stoi() function to each element of a vector obtained by splitting a user input by space
    std::tuple<int, int, int> ABC = std::make_tuple(std::stoi(std::string(std::cin.getline(new char[100], 100), '\n')), std::stoi(std::string(std::cin.getline(new char[100], 100), '\n')), std::stoi(std::string(std::cin.getline(new char[100], 100), '\n')));

    // Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
    if (std::count(std::begin(ABC), std::end(ABC), 5) == 2) {
        // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
        std::cout << (std::accumulate(std::begin(ABC), std::end(ABC), 0) == 17? "YES" : "NO") << std::endl;
    } else {
        // If the condition is not met, print 'NO'
        std::cout << "NO" << std::endl;
    }

    return 0;
}
