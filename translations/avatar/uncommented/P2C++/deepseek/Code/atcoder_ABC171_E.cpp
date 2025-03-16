#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <functional> // for std::bit_xor
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    int total = std::accumulate(a.begin(), a.end(), 0, std::bit_xor<int>());

    std::ostringstream oss;
    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            oss << " ";
        }
        oss << (a[i] ^ total);
    }
    std::cout << oss.str() << std::endl;

    return 0;
}
