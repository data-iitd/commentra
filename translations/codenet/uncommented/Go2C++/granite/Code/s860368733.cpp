
#include <iostream>
#include <map>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> h;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        h[i] = tmp;
    }
    std::map<int, int> counter;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        if (h[a-1] < h[b-1]) {
            counter[a] = 1;
        } else if (h[a-1] > h[b-1]) {
            counter[b] = 1;
        } else if (h[a-1] == h[b-1]) {
            counter[a] = 1;
            counter[b] = 1;
        }
    }
    int ans = 0;
    for (auto it = h.begin(); it!= h.end(); it++) {
        if (counter.find(it->first) == counter.end()) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
