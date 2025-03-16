

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;  // Take an integer input representing the number of elements in the list `m`
    std::vector<std::vector<int>> m(n);  // Create a vector of vectors `m` where each subvector contains two integers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int x;
            std::cin >> x;
            m[i].push_back(x);
        }
    }
    std::sort(m.begin(), m.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a[1] > b[1]; });  // Sort the vector `m` in descending order based on the second element of each subvector
    std::vector<int> a = m[0];  // Assign the first element of the sorted vector `m` to the variable `a`

    // Iterate over the rest of the elements in `m` starting from the second element
    for (int i = 1; i < n; i++) {
        if (m[i][1] > a[1]) {  // Check if the second element of the current element `m[i]` is greater than the second element of the variable `a`
            std::cout << "Happy Alex" << std::endl;  // If true, print "Happy Alex" and break out of the loop
            break;
        }
        a = m[i];  // If false, assign the current element `m[i]` to the variable `a`
    }
    if (i == n) {  // If the loop completes without breaking
        std::cout << "Poor Alex" << std::endl;  // Print "Poor Alex"
    }

    return 0;
}
