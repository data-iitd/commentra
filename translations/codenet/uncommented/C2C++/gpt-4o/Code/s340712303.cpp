#include <iostream>
#include <vector>
#define N 2000

int main() {
    int num1, num2, a, ans, sum = 0;
    std::vector<int> math(N + 1, 0);
    math[0] = 1;

    std::cin >> num1;
    for (int i = 0; i < num1; i++) {
        std::cin >> a;
        sum += a;
        for (int j = sum - a; j >= 0; j--) {
            if (math[j] == 1) {
                math[j + a] = 1;
            }
        }
    }

    std::cin >> num2;
    for (int i = 0; i < num2; i++) {
        std::cin >> ans;
        math[ans] == 1 ? std::cout << "yes\n" : std::cout << "no\n";
    }

    return 0;
}

// <END-OF-CODE>
