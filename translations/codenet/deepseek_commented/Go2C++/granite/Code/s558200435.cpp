
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n; // 1. Reading the input number of elements (n)
    std::cin >> n;

    std::vector<int> a(n); // 2. Reading the elements into a vector (a)
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b; // 3. Creating a vector (b) to store the longest increasing subsequence
    for (int v : a) { // 4. Finding the longest increasing subsequence
        int x = std::lower_bound(b.begin(), b.end(), v) - b.begin();
        if (x == b.size()) {
            b.push_back(v);
        } else {
            b[x] = v;
        }
    }

    std::cout << b.size() << std::endl; // 5. Outputting the length of the longest increasing subsequence

    return 0;
}
