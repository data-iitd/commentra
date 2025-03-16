
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'A']++;
    }

    std::sort(count.rbegin(), count.rend());

    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] >= k) {
            res += k * k;
            std::cout << res << std::endl;
            return 0;  // Exit the program since we have found the result
        }
        k -= count[i];
        res += count[i] * count[i];
    }

    std::cout << res << std::endl;

    return 0;
}

