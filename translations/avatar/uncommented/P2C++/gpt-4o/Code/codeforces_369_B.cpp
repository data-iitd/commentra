#include <iostream>
#include <vector>
#include <string>

std::vector<int> get_nums(int num, int t) {
    std::vector<int> result(num);
    for (int i = 0; i < num; ++i) {
        result[i] = (i < t % num) ? (t / num + 1) : (t / num);
    }
    return result;
}

int main() {
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;

    std::vector<int> ans = get_nums(k, sk);
    std::vector<int> temp = get_nums(n - k, sa - sk);
    ans.insert(ans.end(), temp.begin(), temp.end());

    for (size_t i = 0; i < ans.size(); ++i) {
        std::cout << ans[i];
        if (i < ans.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
