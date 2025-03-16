#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> P[i];
        --P[i]; // Convert to 0-based index
    }

    std::map<int, int> map;
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }

    std::vector<int> nglist;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist.push_back(i);
        }
    }

    if (nglist.empty()) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int ans = std::min(N - nglist[0] - 1, nglist.back() + 1);
    for (size_t i = 0; i < nglist.size() - 1; ++i) {
        ans = std::min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans);
    }

    std::cout << ans << std::endl;
    return 0;
}

