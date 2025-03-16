#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int num, k;
    std::cin >> num >> k;
    std::vector<int> arr(num);
    for (int i = 0; i < num; ++i) {
        std::cin >> arr[i];
    }
    std::set<int> different;
    int temp = 0;
    std::sort(arr.begin(), arr.end());
    for (int x : arr) {
        if (x % k != 0 || different.find(x / k) == different.end()) {
            different.insert(x);
        }
        temp = std::max(static_cast<int>(different.size()), temp);
    }
    std::cout << temp << std::endl;
    return 0;
}

