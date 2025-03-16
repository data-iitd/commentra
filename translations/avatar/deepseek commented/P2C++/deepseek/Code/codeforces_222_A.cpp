#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> elems(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> elems[i];
    }
    
    auto all_same = [](const std::vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] != arr[0]) {
                return false;
            }
        }
        return true;
    };
    
    if (all_same(elems)) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    if (k == 1) {
        std::cout << -1 << std::endl;
        return 0;
    }
    
    if (!all_same(std::vector<int>(elems.begin() + k - 1, elems.end()))) {
        std::cout << -1 << std::endl;
        return 0;
    }
    
    int target = elems.back();
    std::vector<int> to_delete(elems.begin(), elems.begin() + k - 1);
    
    while (!to_delete.empty() && to_delete.back() == target) {
        to_delete.pop_back();
    }
    
    std::cout << to_delete.size() << std::endl;
    
    return 0;
}

