#include <iostream>
#include <vector>
#include <algorithm>

int binary_search(int key, const std::vector<std::vector<int>>& ans) {
    // Initialize bad and good indices for binary search
    int bad = -1, good = ans.size();
    
    // Perform binary search to find the correct position
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid].back() < key) {
            good = mid;
        } else {
            bad = mid;
        }
    }
    
    // Return the index where the key should be inserted
    return good;
}

int main() {
    int N;
    std::cin >> N;
    
    // Initialize the list of lists
    std::vector<std::vector<int>> ans;
    
    // Read each element and insert it into the appropriate position
    for (int i = 0; i < N; ++i) {
        int A;
        std::cin >> A;
        int idx = binary_search(A, ans);
        if (idx == ans.size()) {
            // If the key should be inserted at the end, append a new sublist
            ans.push_back({A});
        } else {
            // Otherwise, insert the key into the appropriate sublist
            ans[idx].push_back(A);
        }
    }
    
    // Print the number of unique elements
    std::cout << ans.size() << std::endl;
    
    return 0;
}
