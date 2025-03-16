#include <iostream>
#include <vector>

int main() {
    int a, b, c, d, e;

    std::cin >> a >> b >> c >> d >> e;

    std::vector<int> al = {a, b, c, d, e};

    for (size_t n = 0; n < al.size(); ++n) {
        if (al[n] == 0) {
            std::cout << n + 1 << std::endl;
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
