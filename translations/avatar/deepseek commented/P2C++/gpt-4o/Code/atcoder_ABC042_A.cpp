#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> input(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> input[i];  // Take input from user
    }

    // Create a tuple from the input
    std::tuple<int, int, int> ABC(input[0], input[1], input[2]);

    // Count the number of 5s in the tuple
    int count_of_fives = std::count(input.begin(), input.end(), 5);

    // Check if the tuple contains exactly two 5s
    if (count_of_fives == 2) {
        // Check if the sum of the elements in ABC is 17
        int sum = std::get<0>(ABC) + std::get<1>(ABC) + std::get<2>(ABC);
        std::cout << (sum == 17 ? "YES" : "NO") << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
