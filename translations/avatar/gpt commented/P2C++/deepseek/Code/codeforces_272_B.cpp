#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

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
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> sequence((std::istream_iterator<int>(iss)), std::istream_iterator<int>());

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

    int totalPairs = 0;
    for (int y : FXs) {
        int n = storage[y].size();
        totalPairs += (n * n - n) / 2;
    }

    std::cout << totalPairs << std::endl;
    return 0;
}
