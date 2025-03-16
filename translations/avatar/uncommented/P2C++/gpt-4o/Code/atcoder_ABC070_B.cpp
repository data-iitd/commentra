#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> A(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> A[i];
    }

    if (A[1] <= A[2] || A[3] <= A[0]) {
        std::cout << 0 << std::endl;
    } else {
        std::sort(A.begin(), A.end());
        std::cout << A[2] - A[1] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
