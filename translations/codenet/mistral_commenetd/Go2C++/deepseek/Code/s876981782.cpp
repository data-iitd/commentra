#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

int main() {
    int N;
    std::cin >> N;

    std::vector<double> values(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> values[i];
    }

    std::sort(values.begin(), values.end());

    double generated = 0.0;
    for (int i = 0; i < N - 1; ++i) {
        generated = (values[i] + values[i + 1]) / 2;
        values[i + 1] = generated;
    }

    std::cout << generated << std::endl;

    return 0;
}

