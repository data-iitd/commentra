#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }
    std::sort(l.begin(), l.end());
    int high = 1;
    int tower = n;
    int maximum = 1;
    for (int i = 1; i < n; ++i) {
        if (l[i] == l[i - 1]) {
            tower -= 1;
            high += 1;
        } else {
            if (high > maximum) {
                maximum = high;
            }
            high = 1;
        }
    }
    if (high > maximum) {
        maximum = high;
    }
    std::cout << maximum << " " << tower << std::endl;
    return 0;
}

