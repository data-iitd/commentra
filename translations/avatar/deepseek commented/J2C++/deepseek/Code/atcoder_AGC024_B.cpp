#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> P[i];
        --P[i]; // Adjust to 0-based index
    }

    // Create a map to map each value in P to its index
    std::unordered_map<int, int> map;
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }

    // Create a vector to store indices of elements that are out of order
    std::vector<int> nglist;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist.push_back(i); // Add the index to nglist if the current element is greater than the next element
        }
    }

    // If nglist is empty, the array P is already sorted
    if (nglist.empty()) {
        std::cout << 0 << std::endl; // Print 0 and return as the array is sorted
        return 0;
    }

    // Calculate the minimum number of swaps required to sort the array P
    int ans = std::min(N - nglist.front() - 1, nglist.back() + 1);
    for (size_t i = 0; i < nglist.size() - 1; ++i) {
        ans = std::min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans);
    }

    // Print the minimum number of swaps required
    std::cout << ans << std::endl;

