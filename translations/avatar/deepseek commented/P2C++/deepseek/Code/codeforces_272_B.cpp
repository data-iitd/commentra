#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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

int nPairsWithCommonFX(const std::vector<int>& sequence) {
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
    int count = 0;
    for (int y : FXs) {
        count += storage[y].size() * storage[y].size();
    }
    return (count - static_cast<int>(FXs.size())) / 2;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> sequence;
    int value;
    while (iss >> value) {
        sequence.push_back(value);
    }
    std::cout << nPairsWithCommonFX(sequence) << std::endl;
    return 0;
}
