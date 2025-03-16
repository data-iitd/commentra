#include <iostream>

int main() {
    int a, c, k, b;
    while (std::cin >> a) {
        c = 0, k = 0;
        if (a < 3)
            std::cout << "0\n";
        else {
            b = a;
            while (a--) {
                b--;
                c++;
                if (c == 3) {
                    k++;
                    c = 0;
                }
            }
            std::cout << k << "\n";
        }
    }
    return 0;
}

// <END-OF-CODE>
