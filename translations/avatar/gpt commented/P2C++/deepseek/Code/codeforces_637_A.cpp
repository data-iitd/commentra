#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cin.ignore();  // To ignore the newline character after reading n

    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> s;
    std::string word;
    for (char c : input) {
        if (c == ' ') {
            s.push_back(word);
            word.clear();
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        s.push_back(word);
    }

    std::unordered_map<std::string, int> w;
    for (const auto& word : s) {
        w[word]++;
    }

    std::reverse(s.begin(), s.end());

    int c = -1, a = 0;
    for (const auto& entry : w) {
        if (entry.second == *std::max_element(w.begin(), w.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second < b.second;
        })) {
            auto it = std::find(s.begin(), s.end(), entry.first);
            if (it != s.end() && std::distance(s.begin(), it) > c) {
                c = std::distance(s.begin(), it);
                a = &entry - &*w.begin();
            }
        }
    }

    std::cout << s[c] << '\n';

    return 0;
}
