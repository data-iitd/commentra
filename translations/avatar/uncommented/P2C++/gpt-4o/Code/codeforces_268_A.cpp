#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> q;
    int count = 0;

    // Read input
    for (int i = 0; i < n; i++) {
        std::vector<std::string> a;
        std::string input;
        std::cin >> input;
        a.push_back(input);
        q.push_back(a);
    }

    // Count pairs
    for (const auto& j : q) {
        for (const auto& k : q) {
            if (k == j) {
                continue;
            } else if (j[0] == k.back()) {
                count++;
            } else {
                continue;
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}

// <END-OF-CODE>
