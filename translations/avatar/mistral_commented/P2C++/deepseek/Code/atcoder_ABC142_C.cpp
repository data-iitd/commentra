#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore(); // To ignore the newline character after N

    std::vector<std::pair<int, int>> A;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string token;

    int index = 1;
    while (std::getline(iss, token, ' ')) {
        A.push_back(std::make_pair(index++, std::stoi(token)));
    }

    std::sort(A.begin(), A.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    std::vector<int> A__;
    for (const auto& a : A) {
        A__.push_back(a.first);
    }

    for (size_t i = 0; i < A__.size() - 1; ++i) {
        std::cout << A__[i] << " ";
    }
    std::cout << A__.back() << std::endl;

    return 0;
}
