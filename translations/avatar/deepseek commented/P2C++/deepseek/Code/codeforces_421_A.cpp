#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n, a, b;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    ss >> n >> a >> b;

    std::vector<int> lista;
    std::getline(std::cin, line);
    std::stringstream ss_lista(line);
    int num;
    while (ss_lista >> num) {
        lista.push_back(num);
    }

    std::vector<int> listb;
    std::getline(std::cin, line);
    std::stringstream ss_listb(line);
    while (ss_listb >> num) {
        listb.push_back(num);
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

