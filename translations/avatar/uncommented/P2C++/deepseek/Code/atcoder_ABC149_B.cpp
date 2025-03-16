#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<int> cookies;
    int cookie;
    std::string input;
    std::getline(std::cin, input);
    std::string temp;
    for (char c : input) {
        if (c == ' ') {
            cookies.push_back(std::stoi(temp));
            temp.clear();
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        cookies.push_back(std::stoi(temp));
    }

    int leftOver = cookies[0] - cookies[2];
    int takahashi = std::max(0, leftOver);
    std::cout << std::to_string(takahashi) + " " + (takahashi > 0 ? std::to_string(cookies[1]) : std::to_string(std::max(0, cookies[1] - std::abs(leftOver)))) << std::endl;

    return 0;
}

