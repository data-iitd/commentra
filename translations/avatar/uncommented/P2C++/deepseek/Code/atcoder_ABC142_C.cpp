#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> A;
    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        A.emplace_back(i + 1, x);
    }
    std::sort(A.begin(), A.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });
    std::vector<int> A_;
    for (const auto& a : A) {
        A_.push_back(a.first);
    }
    for (size_t i = 0; i < A_.size() - 1; ++i) {
        std::cout << A_[i] << " ";
    }
    std::cout << A_.back() << std::endl;
    return 0;
}

