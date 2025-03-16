#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n;
    long k;
    std::cin >> n >> k;
    std::vector<long> arr(n);
    std::set<long> set;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            count++;
            set.insert(arr[i]);
        } else if (set.find(arr[i] / k) == set.end()) {
            count++;
            set.insert(arr[i]);
        }
    }
    std::cout << count << std::endl;
    return 0;
}

