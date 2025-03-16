#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, k;
    std::string input;
    std::getline(std::cin, input);
    n = std::stoi(input.substr(0, input.find(' ')));
    k = std::stoi(input.substr(input.find(' ') + 1));

    std::getline(std::cin, input);
    std::vector<int> M;
    std::string temp;
    for (char c : input) {
        if (c != ' ') {
            temp += c;
        } else {
            M.push_back(std::stoi(temp));
            temp.clear();
        }
    }
    if (!temp.empty()) {
        M.push_back(std::stoi(temp));
    }

    int m = 0;

    for (int j = 0; j < n; ++j) {
        for (int p = 0; p < n; ++p) {
            if (M[p] == 0) {
                std::cout << p + 1 << " ";
                break;
            }
        }
        for (int l = 0; l < p + 1 - k; ++l) {
            M[l] -= 1;
        }
        M[p] -= 1;
    }

    std::cout << std::endl;
    return 0;
}
