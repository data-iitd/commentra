
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> l1(n);
    for (int i = 0; i < n; i++) {
        std::cin >> l1[i];
    }
    std::sort(l1.begin(), l1.end());
    int a = l1[n - 1];
    int b = l1[0];
    if (a == b) {
        std::cout << a - b << " " << n * (n - 1) / 2 << std::endl;
    } else {
        int ac = 0, bc = 0;
        for (int i = 0; i < n; i++) {
            if (l1[i] == a) {
                ac++;
            }
            if (l1[i] == b) {
                bc++;
            }
        }
        std::cout << a - b << " " << ac * bc << std::endl;
    }
    return 0;
}
