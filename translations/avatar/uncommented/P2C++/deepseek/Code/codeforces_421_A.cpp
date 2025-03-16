#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n, a, b;
    std::vector<int> lista, listb;

    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    ss >> n >> a >> b;

    std::getline(std::cin, input);
    std::stringstream ss2(input);
    int temp;
    for (int i = 0; i < a; ++i) {
        ss2 >> temp;
        lista.push_back(temp);
    }

    std::getline(std::cin, input);
    std::stringstream ss3(input);
    for (int i = 0; i < b; ++i) {
        ss3 >> temp;
        listb.push_back(temp);
    }

    for (int k = 0; k < n; ++k) {
        if (std::find(lista.begin(), lista.end(), k + 1) != lista.end()) {
            std::cout << 1 << " ";
        } else {
            std::cout << 2 << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}
