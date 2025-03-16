#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    if (s.empty()) {
        return 0;
    }

    std::vector<int> counter;
    int count = 0;

    for (char c : s) {
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            count++;
        } else {
            counter.push_back(count);
            count = 0;
        }
    }

    counter.push_back(count);
    std::sort(counter.begin(), counter.end());
    std::cout << counter.back() << std::endl;

    return 0;
}

