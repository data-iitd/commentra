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

    for (int i = 0; i < loop; ++i) {
        for (int j = 0; j < div; ++j) {
            if (i % 2 == 0) {
                std::cout << odd[j] << " " << even[even.size() - 1 - j] << " ";
            } else {
                std::cout << even[j] << " " << odd[odd.size() - 1 - j] << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
