#include <iostream>
#include <iomanip>

int main() {
    double a;
    double ave = 0;
    
    for (int i = 0; i < 5; i++) {
        std::cin >> a;
        if (a <= 40) {
            ave += 40;
        } else {
            ave += a;
        }
    }
    
    ave /= 5.0;
    
    std::cout << std::fixed << std::setprecision(0) << ave << std::endl;
    
    return 0;
}

// <END-OF-CODE>
