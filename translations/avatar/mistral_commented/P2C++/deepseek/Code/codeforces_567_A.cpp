#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int inp;
    std::cin >> inp;
    std::vector<int> lista;

    std::string line;
    std::getline(std::cin, line); // To consume the newline character left in the input buffer
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int num;
    while (stream >> num) {
        lista.push_back(num);
    }

    for (int i = 0; i < lista.size(); ++i) {
        if (i == 0) {
            std::cout << (lista[i + 1] - lista[i]) << " " << (lista[lista.size() - 1] - lista[i]) << std::endl;
            continue;
        }
        if (i == lista.size() - 1) {
            std::cout << (lista[lista.size() - 1] - lista[lista.size() - 2]) << " " << (lista[lista.size() - 1] - lista[0]) << std::endl;
            continue;
        }
        if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            std::cout << (lista[i + 1] - lista[i]) << " ";
        } else {
            std::cout << (lista[i] - lista[i - 1]) << " " << (lista[i] - lista[0]) << " ";
            if (lista[lista.size() - 1] - lista[i] > lista[i] - lista[0]) {
                std::cout << (lista[lista.size() - 1] - lista[i]) << std::endl;
            } else {
                std::cout << (lista[i] - lista[0]) << std::endl;
            }
        }
    }

    return 0;
}
