#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b; // The first line takes three integers n, a, and b as input.
    
    std::vector<int> lista;
    for (int i = 0; i < a; ++i) {
        int x;
        std::cin >> x; // Taking a list of integers lista as input.
        lista.push_back(x);
    }
    
    std::vector<int> listb;
    for (int i = 0; i < b; ++i) {
        int x;
        std::cin >> x; // Taking a list of integers listb as input.
        listb.push_back(x);
    }
    
    for (int k = 0; k < n; ++k) {
        // The for loop iterates over the range n.
        if (std::find(lista.begin(), lista.end(), k + 1) != lista.end()) {
            // If the current index k + 1 is in the list lista,
            std::cout << 1 << " "; // print 1 to the console.
        } else {
            // Otherwise,
            std::cout << 2 << " "; // print 2 to the console.
        }
    }
    
    return 0;
}

// <END-OF-CODE>
