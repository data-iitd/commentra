
#include <iostream>
#include <cmath>

int walkOnMultiplicationTable(int num) {

    int div = 0;
    for (int i = static_cast<int>(std::sqrt(num)); i > 1; i--) {
        if (num%i == 0) {
            div = i;
            break;
        }
    }
    if (div == 0) {
        return num - 1;
    }
    return div + num/div - 2;

}

int main() {
    int a;
    std::cin >> a;
    std::cout << walkOnMultiplicationTable(a) << std::endl;
}

