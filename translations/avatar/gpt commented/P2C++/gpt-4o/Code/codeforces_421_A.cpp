#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    // Read three integers from input: n (number of elements), a, and b
    int n, a, b;
    std::cin >> n >> a >> b;

    // Read a list of integers from input and store it in lista
    std::unordered_set<int> lista;
    for (int i = 0; i < a; ++i) {
        int x;
        std::cin >> x;
        lista.insert(x);
    }

    // Read another list of integers from input and store it in listb
    std::vector<int> listb(b);
    for (int i = 0; i < b; ++i) {
        std::cin >> listb[i];
    }

    // Iterate through the range of n (from 0 to n-1)
    for (int k = 0; k < n; ++k) {
        // Check if the current index + 1 is present in lista
        if (lista.find(k + 1) != lista.end()) {
            // If present, print 1 followed by a space
            std::cout << 1 << " ";
        } else {
            // If not present, print 2 followed by a space
            std::cout << 2 << " ";
        }
    }

    return 0;
}
// <END-OF-CODE>
