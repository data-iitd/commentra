#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(5);
    
    for (int i = 0; i < 5; ++i) {
        std::cin >> A[i];
    }
    
    int minA = *std::min_element(A.begin(), A.end());
    std::cout << static_cast<int>(std::ceil(static_cast<double>(N) / minA)) + 4 << std::endl;

    return 0;
}

// <END-OF-CODE>
