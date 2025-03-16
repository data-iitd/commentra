#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> lista(a);
    std::unordered_set<int> set_lista;

    for (int i = 0; i < a; ++i) {
        std::cin >> lista[i];
        set_lista.insert(lista[i]);
    }

    std::vector<int> listb(b);
    for (int i = 0; i < b; ++i) {
        std::cin >> listb[i];
    }

    for (int k = 0; k < n; ++k) {
        if (set_lista.find(k + 1) != set_lista.end()) {
            std::cout << 1 << " ";
        } else {
            std::cout << 2 << " ";
        }
    }

    return 0;
}
// <END-OF-CODE>
