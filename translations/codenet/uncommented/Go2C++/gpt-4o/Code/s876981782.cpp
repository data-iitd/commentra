#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<double> values(N);
    for (int i = 0; i < N; i++) {
        std::cin >> values[i];
    }

    std::sort(values.begin(), values.end());
    double generated;
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2;
        values[i + 1] = generated;
    }

    std::cout << generated << std::endl;
    return 0;
}

// <END-OF-CODE>
