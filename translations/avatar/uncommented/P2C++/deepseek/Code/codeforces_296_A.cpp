#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> m;
    std::string input;
    std::cin >> input;
    std::string word;
    for (char c : input) {
        if (c == ' ') {
            m.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        m.push_back(word);
    }

    std::unordered_set<std::string> unique_words(m.begin(), m.end());
    bool possible = true;
    for (const auto& i : unique_words) {
        if (std::count(m.begin(), m.end(), i) >= n / 2 + 1) {
            possible = false;
            break;
        }
    }
    std::cout << (possible ? "YES" : "NO") << std::endl;
    return 0;
}
