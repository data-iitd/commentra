#include <iostream>
#include <vector>
#include <algorithm>

int binary_search(int key, const std::vector<std::vector<int>>& ans) {
    int bad = -1, good = ans.size();
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid].back() < key) {
            good = mid;
        } else {
            bad = mid;
        }
    }
    return good;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < N; ++i) {
        int A;
        std::cin >> A;
        int idx = binary_search(A, ans);
        if (idx == ans.size()) {
            ans.push_back({A});
        } else {
            ans[idx].push_back(A);
        }
    }
    std::cout << ans.size() << std::endl;
    return 0;
}
