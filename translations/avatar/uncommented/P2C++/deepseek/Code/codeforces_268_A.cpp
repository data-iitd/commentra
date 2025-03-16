#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> q;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        std::string a;
        std::cin >> a;
        q.push_back(a);
    }

    for (const auto& j : q) {
        for (const auto& k : q) {
            if (&k == &j) continue;
            if (j[0] == k[k.size() - 1]) {
                ++count;
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}

