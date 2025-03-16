#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::map<int, int> idorder;
    for (int i = 1; i <= N; ++i) {
        int A;
        std::cin >> A;
        idorder[A] = i;
    }
    for (int i = 1; i <= N; ++i) {
        std::cout << idorder[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

