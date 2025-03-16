#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

int main() {
    int n;
    std::cin >> n;

    int square = n * n;
    std::vector<int> odd;
    std::vector<int> even;

    for (int i = 1; i <= square; ++i) {
        if (i % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    int loop = square / n;
    int div = loop / 2;

    for (int i = 1; i <= loop; ++i) {
        for (int j = 0; j < div; ++j) {
            if (i % 2 == 1) {
                std::cout << odd.front() << " " << even.back() << " ";
                odd.erase(odd.begin());
                even.pop_back();
            } else {
                std::cout << even.front() << " " << odd.back() << " ";
                even.erase(even.begin());
                odd.pop_back();
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

