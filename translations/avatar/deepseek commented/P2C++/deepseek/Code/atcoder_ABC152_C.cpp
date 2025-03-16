#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> n(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> n[i];
    }

    int a = 1;
    int pos = 0;

    for (int i = 1; i < N; ++i) {
        if (n[pos] > n[i]) {
            a++;
            pos = i;
        }
    }

    std::cout << a << std::endl;

    return 0;
}
