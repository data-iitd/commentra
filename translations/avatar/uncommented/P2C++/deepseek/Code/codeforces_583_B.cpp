#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;
    while (counter < n) {
        counter_turns++;
        for (int i = 0; i < n; ++i) {
            if (a[i] != -1 && a[i] <= counter) {
                counter++;
                a[i] = -1;
            }
        }
        std::reverse(a.begin(), a.end());
    }
    std::cout << counter_turns << std::endl;
    return 0;
}

