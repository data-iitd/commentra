#include <iostream>
#include <vector>
#include <string>

int main() {
    int t, m;
    std::cin >> t >> m;

    std::vector<int> alocuente(m, 0);

    for (int i = 0; i < t; ++i) {
        std::string op;
        std::cin >> op;

        if (op == "alloc") {
            int pos = 0;
            int size;
            std::cin >> size;
            for (int j = 0; j < m; ++j) {
                if (alocuente[j] == 0) {
                    pos++;
                    if (pos == size) {
                        for (int k = j - size + 1; k <= j; ++k) {
                            alocuente[k] = 1;
                        }
                        std::cout << (j - size + 1) << std::endl;
                        break;
                    }
                } else {
                    pos = 0;
                }
            }
            if (pos != size) {
                std::cout << "NULL" << std::endl;
            }
        } else if (op == "erase") {
            int index;
            std::cin >> index;
            if (index < 0 || index >= m || alocuente[index] == 0) {
                std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
            } else {
                alocuente[index] = 0;
            }
        } else if (op == "defragment") {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            std::vector<int> new_alocuente;
            for (int j = 0; j < m; ++j) {
                if (alocuente[j] != 0) {
                    new_alocuente.push_back(alocuente[j]);
                }
            }
            for (int j = 0; j < cnt; ++j) {
                new_alocuente.push_back(0);
            }
            alocuente = new_alocuente;
        }
    }

    return 0;
}
