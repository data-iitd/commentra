#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    long long sum = 0;
    long long wa = 0;
    std::vector<int> A(N);
    std::vector<int> sa(N);
    int ans = 0;
    int shou;
    long long min = 1123456789;

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
        wa += i + 1;
    }

    if (sum % wa) {
        ans = 0;
    } else {
        shou = sum / wa;
        for (int i = 0; i < N; i++) {
            sa[i] = A[(i + 1) % N] - A[i] - shou;
        }

        for (int i = 0; i < N - 1; i++) {
            if (sa[i] <= 0 && !(sa[i] % N)) {
                ans = 1;
            } else {
                ans = 0;
                break;
            }
        }
    }

    if (ans) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
