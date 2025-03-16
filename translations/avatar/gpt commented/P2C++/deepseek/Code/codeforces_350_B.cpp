#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> t(n + 1);
    std::vector<int> a(n + 1);
    std::vector<int> cnt(n + 1, 0);
    std::vector<int> ans;

    // Read the list 't' and prepend a 0 for 1-based indexing
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i];
    }

    // Read the list 'a' and prepend a 0 for 1-based indexing
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        cnt[a[i]]++;
    }

    // Iterate through each index from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Check if the current element in 't' is 1
        if (t[i] == 1) {
            // Initialize a current path list starting with the current index
            std::vector<int> crt;
            crt.push_back(i);
            // Set x to the corresponding value in 'a'
            int x = a[i];

            // Continue to follow the chain while the count of x is 1
            while (cnt[x] == 1) {
                crt.push_back(x);  // Add x to the current path
                x = a[x];  // Move to the next index in the chain
            }

            // Update the answer if the current path is longer than the previous answer
            if (crt.size() > ans.size()) {
                ans = crt;  // Store a copy of the current path
            }
        }
    }

    // Reverse the answer list to maintain the original order
    std::reverse(ans.begin(), ans.end());

    // Print the length of the longest path found
    std::cout << ans.size() << std::endl;

    // Print the elements of the longest path as a space-separated string
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << ans[i];
    }
    std::cout << std::endl;

    return 0;
}
