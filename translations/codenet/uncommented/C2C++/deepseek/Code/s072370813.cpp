#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    long long sum = 0;
    long long wa = 0;
    long long min = 1123456789;

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
        wa += i + 1;
    }

    if (sum % wa != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    long long shou = sum / wa;
    std::vector<int> sa(N);
    int ans = 1;

    for (int i = 0; i < N; i++) {
        sa[i] = A[(i + 1) % N] - A[i] - shou;
        if (sa[i] != 0) {
            ans = 0;
            break;
        }
    }

    if (ans) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
