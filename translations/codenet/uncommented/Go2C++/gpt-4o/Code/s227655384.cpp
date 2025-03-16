#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

void PrintList(const std::vector<int>& list) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (i == 0) {
            std::cout << list[i];
        } else {
            std::cout << " " << list[i];
        }
    }
    std::cout << std::endl;
}

int main() {
    std::set<int> m;
    std::string line;

    // Read 4 lines of input
    for (int i = 0; i < 4; ++i) {
        std::getline(std::cin, line);
        if (i == 1) {
            std::istringstream iss(line);
            int n;
            while (iss >> n) {
                m.insert(n);
            }
        }
    }

    std::vector<int> result;
    std::istringstream iss(line);
    int n;
    while (iss >> n) {
        if (m.count(n)) {
            m.erase(n);
        } else {
            m.insert(n);
        }
    }

    for (const auto& k : m) {
        result.push_back(k);
    }

    std::sort(result.begin(), result.end());
    PrintList(result);

    return 0;
}

// <END-OF-CODE>
