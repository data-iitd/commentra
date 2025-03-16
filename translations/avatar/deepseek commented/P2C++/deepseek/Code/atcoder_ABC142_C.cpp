#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A;
    std::string line;
    std::getline(std::cin, line); // To consume the newline character
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::string token;
    int index = 0;
    while (std::getline(iss, token, ' ')) {
        A.push_back(std::make_pair(index + 1, std::stoi(token)));
        index++;
    }

    std::sort(A.begin(), A.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    for (size_t i = 0; i < A.size(); ++i) {
        if (i != A.size() - 1) {
            std::cout << A[i].first << " ";
        } else {
            std::cout << A[i].first << std::endl;
        }
    }

    return 0;
}
