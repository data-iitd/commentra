#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> A(N);
    
    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        A[i] = {i + 1, x};
    }
    
    std::sort(A.begin(), A.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });
    
    for (int i = 0; i < N - 1; ++i) {
        std::cout << A[i].first << " ";
    }
    std::cout << A[N - 1].first << std::endl;

    return 0;
}

// <END-OF-CODE>
