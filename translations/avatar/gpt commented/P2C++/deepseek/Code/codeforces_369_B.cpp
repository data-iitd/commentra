#include <iostream>
#include <vector>
#include <string>

std::vector<int> get_nums(int num, int t) {
    // Generate a list of numbers based on the distribution of t across num parts
    std::vector<int> result;
    for (int i = 0; i < num; ++i) {
        if (i < t % num) {
            result.push_back(t / num + 1);
        } else {
            result.push_back(t / num);
        }
    }
    return result;
}

int main() {
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;

    // Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
    std::vector<int> ans = get_nums(k, sk) + get_nums(n - k, sa - sk);

    // Print the result as a space-separated string
    std::string result;
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) {
            result += " ";
        }
        result += std::to_string(ans[i]);
    }
    std::cout << result << std::endl;

    return 0;
}
