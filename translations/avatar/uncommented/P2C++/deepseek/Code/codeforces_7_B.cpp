#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int t, m;
    std::cin >> t >> m;
    std::vector<int> alocuente(m, 0);
    int ind = 1;
    std::cin.ignore(); // To ignore the newline character after reading integers

    for (int i = 0; i < t; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<std::string> op;
        std::string word;
        while (iss >> word) {
            op.push_back(word);
        }

        if (op[0] == "alloc") {
            int pos = 0;
            for (int j = 0; j < m; ++j) {
                if (alocuente[j] == 0) {
                    pos += 1;
                    if (pos == std::stoi(op[1])) {
                        for (int k = j - std::stoi(op[1]) + 1; k <= j; ++k) {
                            alocuente[k] = ind;
                        }
                        std::cout << ind << std::endl;
                        ind += 1;
                        break;
                    }
                } else {
                    pos = 0;
                }
            }
            if (pos != std::stoi(op[1])) {
                std::cout << "NULL" << std::endl;
            }
        } else if (op[0] == "erase") {
            int pos = std::stoi(op[1]);
            if (pos <= 0 || pos > ind || alocuente[pos - 1] == 0) {
                std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
            } else {
                for (int j = 0; j < m; ++j) {
                    if (alocuente[j] == pos) {
                        alocuente[j] = 0;
                    }
                }
            }
        } else if (op[0] == "defragment") {
            std::vector<int> temp;
            for (int j = 0; j < m; ++j) {
                if (alocuente[j] != 0) {
                    temp.push_back(alocuente[j]);
                }
            }
            alocuente = temp;
            for (int j = alocuente.size(); j < m; ++j) {
                alocuente.push_back(0);
            }
        }
    }

    return 0;
}
