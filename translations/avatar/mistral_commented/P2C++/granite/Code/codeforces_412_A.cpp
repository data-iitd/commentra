
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Read the number of elements `n` and the number of queries `k` from the standard input
    int n, k;
    std::cin >> n >> k;

    // Read a single string `v` from the standard input
    std::string v;
    std::cin >> v;

    // Initialize a vector `d` with two elements: "LEFT" and "RIGHT"
    std::vector<std::string> d = {"LEFT", "RIGHT"};

    // Determine the direction based on the difference between `k` and `n-k`
    bool f = k - 1 < n - k;

    // Determine the number of elements to be appended to the vector `a`
    int m = std::min(k - 1, n - k);

    // Initialize an empty vector `a`
    std::vector<std::string> a;

    // Append "LEFT" or "RIGHT" to the vector `a` based on the value of `f`
    for (int i = 0; i < m; i++) {
        a.push_back(d[not f]);
    }

    // Iterate through the string `v` with a step of 2 times the value of `f`
    for (int i = 0; i < v.length(); i += 2 * f) {
        // Append "PRINT <character>" and the corresponding direction to the vector `a`
        a.push_back("PRINT " + std::string(1, v[i]));
        a.push_back(d[f]);
    }

    // Print all the elements of the vector `a`, except the last one, separated by newline characters
    for (int i = 0; i < a.size() - 1; i++) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}

