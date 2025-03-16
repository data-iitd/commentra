#include <iostream>
#include <vector>
#include <algorithm>

#define N 1000000
#define Q 50000

int n;
std::vector<int> S(N);
std::vector<int> T(Q);

int binarySearch(int key) {
    int left = 0, right = n, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (S[mid] == key) return 1;
        else if (key < S[mid]) right = mid;
        else left = mid + 1;
    }
    return 0;
}

int main() {
    int q, c = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> T[i];
        if (binarySearch(T[i]) == 1) c++;
    }

    std::cout << c << std::endl;

    return 0;
}

// <END-OF-CODE>
