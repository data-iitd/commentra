#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    int n, k;
    sscanf(input.c_str(), "%d %d", &n, &k);

    std::vector<int> M;
    std::getline(std::cin, input);
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(' ')) != std::string::npos) {
        token = input.substr(0, pos);
        M.push_back(std::stoi(token));
        input.erase(0, pos + 1);
    }
    M.push_back(std::stoi(input));

    int m = 0;

    for (int j = 0; j < n; ++j) {
        for (int p = 0; p < n; ++p) {
            if (M[p] == 0) {
                std::cout << (p + 1) << " ";
                break;
            }
        }

        for (int l = 0; l < (p + 1 - k); ++l) {
            M[l] -= 1;
        }

        M[p] -= 1;
    }

    std::cout << std::endl;
    return 0;
}
