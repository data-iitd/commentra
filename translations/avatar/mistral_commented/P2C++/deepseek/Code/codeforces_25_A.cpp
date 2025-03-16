#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> list;
    std::string input;
    std::getline(std::cin, input); // Read the newline character
    std::getline(std::cin, input);

    std::stringstream ss(input);
    int x;
    while (ss >> x) {
        list.push_back(x % 2);
    }

    if (std::accumulate(list.begin(), list.end(), 0) == 1) {
        std::cout << "The first number with remainder 1 is: " << std::distance(list.begin(), std::find(list.begin(), list.end(), 1)) + 1 << std::endl;
    } else {
        std::cout << "The first number with remainder 0 is: " << std::distance(list.begin(), std::find(list.begin(), list.end(), 0)) + 1 << std::endl;
    }

    return 0;
}
