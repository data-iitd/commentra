#include <iostream>
#include <string>
#include <vector>
#include <cctype> // for isspace, ispunct

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::vector<char> res;
    std::vector<char> punctuation = {',', '.', '!', '?'};

    for (size_t i = 0; i < s.length(); ++i) {
        if (i > 0) {
            if (isspace(s[i])) {
                if (!res.empty() && res.back() != ' ') {
                    res.push_back(s[i]);
                }
            } else {
                if (ispunct(s[i])) {
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
            if (!isspace(s[i])) {
                if (!ispunct(s[i])) {
                    res.push_back(s[i]);
                }
            }
        }
    }

    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
    }
    std::cout << std::endl;

    return 0;
}
