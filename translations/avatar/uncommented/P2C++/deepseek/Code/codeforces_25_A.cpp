#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> list;
    std::string input;
    std::getline(std::cin, input); // To consume the newline character
    std::getline(std::cin, input);
    std::stringstream ss(input);
    int x;
    while (ss >> x) {
        list.push_back(x % 2);
    }
    if (std::accumulate(list.begin(), list.end(), 0) == 1) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i] == 1) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    } else {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i] == 0) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    }
    return 0;
}
