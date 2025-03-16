#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <functional> // For std::function

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a;
    int temp;
    while (std::cin >> temp) {
        a.push_back(temp);
    }

    int total = 0;
    for (int ai : a) {
        total ^= ai;
    }

    std::vector<int> result;
    for (int ai : a) {
        result.push_back(ai ^ total);
    }

    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) std::cout << " ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
