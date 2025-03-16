#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

int main() {
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int>> problems(q);
    for (auto& p : problems) {
        std::cin >> p.first >> p.second;
    }

    // Create a vector to keep track of 'AC' occurrences
    std::vector<int> cumsum(n + 1, 0);

    // Count occurrences of 'AC' in the string
    for (int i = 1; i < n; ++i) {
        cumsum[i] = cumsum[i - 1];
        if (s.substr(i - 1, 2) == "AC") {
            ++cumsum[i];
        }
    }

    // Process each query to find the number of 'AC' occurrences in the specified range
    for (const auto& p : problems) {
        int l = p.first;
        int r = p.second;
        // Output the difference in cumulative sums to get the count in the range [l, r]
        std::cout << cumsum[r - 1] - cumsum[l - 1] << std::endl;
    }

    return 0;
}
