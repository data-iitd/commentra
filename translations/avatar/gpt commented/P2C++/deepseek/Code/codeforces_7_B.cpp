#include <iostream>
#include <vector>
#include <string>

int main() {
    int t, m;
    std::cin >> t >> m;
    std::vector<int> alocuente(m, 0);
    int ind = 1;

    for (int i = 0; i < t; ++i) {
        std::string op;
        std::cin >> op;

        if (op == "alloc") {
            int pos = 0;
            int size;
            std::cin >> size;
            for (int j = 0; j < m; ++j) {
                if (alocuente[j] == 0) {
                    pos += 1;
                    if (pos == size) {
                        for (int k = j - size + 1; k <= j; ++k) {
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
            if (pos != size) {
                std::cout << "NULL" << std::endl;
            }
        } else if (op == "erase") {
            int id;
            std::cin >> id;
            if (id == 0 || std::find(alocuente.begin(), alocuente.end(), id) == alocuente.end()) {
                std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
            } else {
                for (int j = 0; j < m; ++j) {
                    if (alocuente[j] == id) {
                        alocuente[j] = 0;
                    }
                }
            }
        } else if (op == "defragment") {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (alocuente[j] == 0) {
                    cnt += 1;
                }
            }
            std::vector<int> temp;
            for (int j = 0; j < m; ++j) {
                if (alocuente[j] != 0) {
                    temp.push_back(alocuente[j]);
                }
            }
            for (int j = 0; j < m; ++j) {
                if (j < temp.size()) {
                    alocuente[j] = temp[j];
                } else {
                    alocuente[j] = 0;
                }
            }
        }
    }

    return 0;
}
