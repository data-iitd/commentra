#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> list(n);

    for (int i = 0; i < n; i++) {
        std::cin >> list[i];
    }

    std::sort(list.begin(), list.end());

    int c = 1;

    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }

    std::printf("%d\n", c);
    return 0;
}
