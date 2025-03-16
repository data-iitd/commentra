#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> list;
    std::string line;
    std::getline(std::cin, line); // Read the newline character
    std::getline(std::cin, line);

    std::stringstream ss(line);
    int num;
    while (ss >> num) {
        list.push_back(num % 2);
    }

    if (std::count(list.begin(), list.end(), 1) == 1) {
        std::cout << std::distance(list.begin(), std::find(list.begin(), list.end(), 1)) + 1 << std::endl;
    } else {
        std::cout << std::distance(list.begin(), std::find(list.begin(), list.end(), 0)) + 1 << std::endl;
    }

    return 0;
}
