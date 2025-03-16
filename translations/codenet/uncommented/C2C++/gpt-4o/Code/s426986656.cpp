#include <iostream>

int main() {
    int A, B, flag = 0;
    std::cin >> A >> B;

    for(int i = 1; i <= 3; ++i) {
        if((A * B * i) % 2 == 1) {
            flag = 1;
            break;
        }
    }

    if(flag) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}

// <END-OF-CODE>
