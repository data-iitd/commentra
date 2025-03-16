#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::string> res;
    std::string punctuation = ",.!?";

    for (size_t i = 0; i < s.length(); ++i) {
        if (i >= 1) {
            if (s[i] == ' ') {
                if (!res.empty() && res.back() != ' ') {
                    res.push_back(s[i]);
                } else {
                    continue;
                }
            } else {
                if (punctuation.find(s[i]) != std::string::npos) {
                    if (!res.empty() && res.back() == ' ') {
                        res.pop_back();
                    }
                    res.push_back(s[i]);
                    res.push_back(' ');
                } else {
                    res.push_back(s[i]);
                }
            }
        } else {
            if (s[i] == ' ') {
                continue;
            }
            if (punctuation.find(s[i]) != std::string::npos) {
                continue;
            } else {
                res.push_back(s[i]);
            }
        }
    }

    std::string result;
    for (const auto& ch : res) {
        result += ch;
    }
    std::cout << result << std::endl;

    return 0;
}
