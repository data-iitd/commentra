
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<char> res;

    std::vector<char> punctuation = {',', '.', '!', '?'};

    for (int i = 0; i < s.length(); i++) {
        if (i >= 1) {
            if (s[i] =='') {
                if (res[res.size() - 1]!='') {
                    res.push_back(s[i]);
                }
            } else {
                if (std::find(punctuation.begin(), punctuation.end(), s[i])!= punctuation.end()) {
                    if (res[res.size() - 1] =='') {
                        res.pop_back();
                    }
                    res.push_back(s[i]);
                    res.push_back(' ');
                } else {
                    res.push_back(s[i]);
                }
            }
        } else {
            if (s[i] =='') {
                continue;
            }
            if (std::find(punctuation.begin(), punctuation.end(), s[i])!= punctuation.end()) {
                continue;
            }
            res.push_back(s[i]);
        }
    }

    std::string result;
    for (char c : res) {
        result += c;
    }
    std::cout << result << std::endl;

    return 0;
}
