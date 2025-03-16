#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after the integer input

    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> sentences;
    std::regex re("\\s*([.?!])\\s*");
    std::sregex_token_iterator iter(input.begin(), input.end(), re, {0, 1});
    std::sregex_token_iterator end;

    while (iter != end) {
        sentences.push_back(*iter++);
    }

    int ans = 1, sumL = 0;
    for (const auto& s : sentences) {
        std::string temp = s + ".";
        int L = temp.length();
        if (L > 1) {
            if (L > n) {
                std::cout << "Impossible" << std::endl;
                return 0;
            }
            if (sumL + L + (sumL > 0) > n) {
                ans++;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

