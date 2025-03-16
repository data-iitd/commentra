
```cpp
#include <iostream>
#include <cmath>

int main() {
    double n, k;
    std::cin >> n >> k;

    double x = 0.0;
    while (true) {
        double under = pow(k, x);
        double upper = pow(k, x + 1);

        if (under <= n && n < upper) {
            std::cout << x + 1 << std::endl;
            return 0;
        }
        x++;
    }

    return 0;
}

