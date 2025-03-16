#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N + 1);
    std::vector<int> B(N);

    for (int i = 0; i < N + 1; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        // site i
        if (A[i] >= B[i]) {
            ans += B[i];
            A[i] -= B[i];
            B[i] = 0;
        } else {
            ans += A[i];
            B[i] -= A[i];
            A[i] = 0;
        }

        // site i + 1
        if (A[i + 1] >= B[i]) {
            ans += B[i];
            A[i + 1] -= B[i];
            B[i] = 0;
        } else {
            ans += A[i + 1];
            B[i] -= A[i + 1];
            A[i + 1] = 0;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
