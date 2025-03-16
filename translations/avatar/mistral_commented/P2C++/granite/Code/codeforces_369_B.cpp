

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> get_nums(int num, int t) {
    std::vector<int> ans;
    for (int i = 0; i < num; i++) {
        ans.push_back(t / num + 1);
    }
    for (int i = 0; i < t % num; i++) {
        ans[i]++;
    }
    return ans;
}

int main() {
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;
    std::vector<int> ans = get_nums(k, sk) + get_nums(n - k, sa - sk);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

