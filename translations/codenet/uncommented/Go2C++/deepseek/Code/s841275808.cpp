#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

int ScanInt() {
    int i;
    std::cin >> i;
    return i;
}

double ScanFloat64() {
    double f;
    std::cin >> f;
    return f;
}

std::string ScanText() {
    std::string s;
    std::cin >> s;
    return s;
}

int Max(int a, int b) {
    return a < b ? b : a;
}

int Min(int a, int b) {
    return a > b ? b : a;
}

int Abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N = ScanInt();
    std::vector<int> X(N);
    std::vector<int> Y(N);
    for (int i = 0; i < N; i++) {
        X[i] = ScanInt();
        Y[i] = X[i];
    }

    std::sort(Y.begin(), Y.end());
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            std::cout << m2 << '\n';
        } else {
            std::cout << m1 << '\n';
        }
    }

    return 0;
}
