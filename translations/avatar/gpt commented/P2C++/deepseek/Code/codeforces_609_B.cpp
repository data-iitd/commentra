#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> lst(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lst[i];
    }

    std::unordered_map<int, int> l;

    for (int i = 0; i < n; ++i) {
        if (l.find(lst[i]) == l.end()) {
            l[lst[i]] = 1;
        } else {
            l[lst[i]] += 1;
        }
    }

    long long res = 0;

    for (int i = 0; i < n; ++i) {
        if (l[lst[i]] > 1) {
            res += n - i - l[lst[i]];
            l[lst[i]] -= 1;
        } else {
            res += n - i - 1;
        }
    }

    std::cout << res << std::endl;

    return 0;
}
