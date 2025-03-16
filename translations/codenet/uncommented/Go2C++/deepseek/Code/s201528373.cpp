#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n;
    std::cin >> x;
    std::vector<int> l;
    for (int i = 0; i < n; i++) {
        int tmpL;
        std::cin >> tmpL;
        l.push_back(tmpL);
    }

    int tmpSum = 0;
    int rs = 0;
    for (int i = 0; i < n; i++) {
        tmpSum += l[i];
        if (tmpSum <= x) {
            rs = i + 2;
        } else {
            break;
        }
    }
    std::cout << rs << std::endl;
}

