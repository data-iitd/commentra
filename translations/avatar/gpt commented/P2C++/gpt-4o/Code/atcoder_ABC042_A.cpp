#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> numbers;
    int num;

    // Read integers from input and store them in a vector
    while (iss >> num) {
        numbers.push_back(num);
    }

    // Convert vector to tuple
    std::tuple<int, int, int> ABC = std::make_tuple(numbers[0], numbers[1], numbers[2]);

    // Count occurrences of 5
    int count_of_5 = std::count(numbers.begin(), numbers.end(), 5);

    // Check if the number 5 appears exactly twice
    if (count_of_5 == 2) {
        // If 5 appears twice, check if the sum of the numbers equals 17
        int sum = std::get<0>(ABC) + std::get<1>(ABC) + std::get<2>(ABC);
        std::cout << (sum == 17 ? "YES" : "NO") << std::endl;
    } else {
        // If 5 does not appear exactly twice, print 'NO'
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
