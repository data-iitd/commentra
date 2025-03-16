#include <iostream>
#include <algorithm>
#include <cmath>

int Abs(int x) {
    return (x < 0) ? -x : x;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    int x = N % K;
    x = min(Abs(x - K), x);
    std::cout << x << std::endl;

    return 0;
}

// <END-OF-CODE>
