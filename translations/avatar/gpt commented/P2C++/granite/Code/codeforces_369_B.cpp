
#include <iostream>
#include <vector>

std::vector<int> get_nums(int num, int t) {
    // Generate a vector of numbers based on the distribution of t across num parts
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
    // Read input values for n, k, l, r, sa, and sk
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;

    // Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
    std::vector<int> ans = get_nums(k, sk) + get_nums(n - k, sa - sk);

    // Print the result as a space-separated string
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

