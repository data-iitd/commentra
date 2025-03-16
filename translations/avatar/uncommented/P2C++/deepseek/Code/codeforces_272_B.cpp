#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    std::unordered_map<int, std::vector<int>> storage;
    std::vector<int> FXs;

    for (int value : sequence) {
        int y = f(value);
        if (storage.find(y) == storage.end()) {
            storage[y] = {value};
            FXs.push_back(y);
        } else {
            storage[y].push_back(value);
        }
    }

    int sum_pairs = 0;
    for (int y : FXs) {
        sum_pairs += storage[y].size() * storage[y].size();
    }

    int sum_single = 0;
    for (int y : FXs) {
        sum_single += storage[y].size();
    }

    int result = (sum_pairs - sum_single) / 2;
    std::cout << result << std::endl;

    return 0;
}
