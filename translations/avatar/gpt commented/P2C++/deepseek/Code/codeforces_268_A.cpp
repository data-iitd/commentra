#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::string>> q;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        std::vector<std::string> a;
        std::string temp;
        while (std::cin >> temp) {
            a.push_back(temp);
        }
        q.push_back(a);
    }

    for (const auto& j : q) {
        for (const auto& k : q) {
            if (&j == &k) continue;
            if (j.front() == k.back()) {
                ++count;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
