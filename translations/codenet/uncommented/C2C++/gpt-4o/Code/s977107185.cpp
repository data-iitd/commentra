#include <iostream>
#include <vector>

int main() {
    int N, tmp, count = 0;
    std::cin >> N;
    std::vector<int> A(N);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                count++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << A[i];
        if (i < N - 1) std::cout << " ";
    }

    std::cout << std::endl;
    std::cout << count << std::endl;

    return 0;
}

// <END-OF-CODE>
