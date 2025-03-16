#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

int main() {
    std::string a;
    std::getline(std::cin, a);
    int count_ones = 0;
    for (char c : a) {
        if (c == '1') {
            count_ones++;
        }
    }
    if (count_ones == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::stringstream ss(a);
        std::string segment;
        std::vector<int> counts;
        while (std::getline(ss, segment, '1')) {
            if (!segment.empty()) {
                counts.push_back(segment.length() + 1);
            }
        }
        int result = 1;
        for (int count : counts) {
            result *= count;
        }
        std::cout << result << std::endl;
    }
    return 0;
}
