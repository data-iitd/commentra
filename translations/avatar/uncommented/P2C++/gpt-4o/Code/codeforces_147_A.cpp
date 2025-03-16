#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::string> res;
    std::vector<char> punctuation = {',', '.', '!', '?'};

    for (size_t i = 0; i < s.length(); i++) {
        if (i >= 1) {
            if (s[i] == ' ') {
                if (!res.empty() && res.back() != " ") {
                    res.push_back(" ");
                }
            } else {
                if (std::find(punctuation.begin(), punctuation.end(), s[i]) != punctuation.end()) {
                    if (!res.empty() && res.back() == " ") {
                        res.pop_back();
                    }
                    res.push_back(std::string(1, s[i]));
                    res.push_back(" ");
                } else {
                    res.push_back(std::string(1, s[i]));
                }
            }
        } else {
            if (s[i] == ' ') {
                continue;
            }
            if (std::find(punctuation.begin(), punctuation.end(), s[i]) != punctuation.end()) {
                continue;
            } else {
                res.push_back(std::string(1, s[i]));
            }
        }
    }

    std::string result;
    for (const auto& str : res) {
        result += str;
    }
    std::cout << result;

    return 0;
}

// <END-OF-CODE>
