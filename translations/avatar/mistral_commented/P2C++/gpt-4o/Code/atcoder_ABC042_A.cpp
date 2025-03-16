#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input); // Read the entire line of input

    std::istringstream iss(input);
    std::vector<int> numbers;
    int number;

    // Split the input by space and convert to integers
    while (iss >> number) {
        numbers.push_back(number);
    }

    // Create a tuple from the vector
    std::tuple<int, int, int> ABC(numbers[0], numbers[1], numbers[2]);

    // Count occurrences of '5'
    int count_of_fives = std::count(numbers.begin(), numbers.end(), 5);

    // Check the conditions
    if (count_of_fives == 2) {
        int sum = std::get<0>(ABC) + std::get<1>(ABC) + std::get<2>(ABC);
        std::cout << (sum == 17 ? "YES" : "NO") << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
// <END-OF-CODE>
