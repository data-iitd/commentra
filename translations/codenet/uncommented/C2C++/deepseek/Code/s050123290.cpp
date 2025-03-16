#include <iostream>
#define N 1000

int main() {
    char su[N] = { '0' };
    int susum = 0;
    int j = 0;

    while (true) {
        for (j = 0; j <= N; j++) {
            std::cin.get(su[j]);
            if (su[j] == '\n') break;
            susum = susum + (su[j] - '0');
        }
        if (su[0] == '0') break;
        std::cout << susum << std::endl;
        susum = 0;
    }

    return 0;
}
