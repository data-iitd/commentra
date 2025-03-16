#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::vector<std::string> res;
    std::string punctuation = ",.!?";

    std::getline(std::cin, s);

    for (size_t i = 0; i < s.length(); ++i) {
        if (i >= 1) {
            if (s[i] == ' ') {
                if (!res.empty() && res.back() != "") {
                    res.push_back(s.substr(i, 1));
                }
            }
        }

        if (punctuation.find(s[i]) != std::string::npos) {
            if (!res.empty() && res.back() == "") {
                res.pop_back();
                res.push_back(std::string(1, s[i]));
                res.push_back("");
            } else {
                res.push_back(std::string(1, s[i]));
            }
        } else {
            res.push_back(std::string(1, s[i]));
        }
    }

    std::string result;
    for (const auto& str : res) {
        result += str;
    }

    std::cout << result << std::endl;

    return 0;
}
