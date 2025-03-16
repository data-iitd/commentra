#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

int main() {
    int num = 998244353;
    std::string line;
    std::getline(std::cin, line);
    int n = std::stoi(line);
    std::vector<int> ai;
    std::vector<int> bi;

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int a, b;
        ss >> a >> b;
        ai.push_back(a);
        bi.push_back(b);
    }

    std::sort(ai.begin(), ai.end());
    std::sort(bi.begin(), bi.end());

    if (n % 2 == 1) {
        std::cout << bi[bi.size() / 2] - ai[ai.size() / 2] + 1 << std::endl;
    } else {
        double b = (ai[ai.size() / 2] + ai[ai.size() / 2 - 1]) / 2.0;
        double c = (bi[bi.size() / 2] + bi[bi.size() / 2 - 1]) / 2.0;
        std::cout << std::fixed << std::setprecision(0) << 2 * (c - b) + 1 << std::endl;
    }

    return 0;
}
