#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> ABC((std::istream_iterator<int>(iss)), std::istream_iterator<int>());

    int count_of_5 = std::count(ABC.begin(), ABC.end(), 5);
    int sum_of_ABC = std::accumulate(ABC.begin(), ABC.end(), 0);

    if (count_of_5 == 2) {
        std::cout << (sum_of_ABC == 17 ? "YES" : "NO") << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
