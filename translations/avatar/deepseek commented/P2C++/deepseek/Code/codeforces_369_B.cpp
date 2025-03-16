#include <iostream>
#include <vector>
#include <string>

std::vector<int> get_nums(int num, int t) {
    // This function distributes the value t among num parts.
    // It calculates the base number for each part by dividing t by num.
    // It adds 1 to the base number for the first t % num parts.
    std::vector<int> result(num);
    int base = t / num;
    int remainder = t % num;
    for (int i = 0; i < num; ++i) {
        result[i] = base + (i < remainder ? 1 : 0);
    }
    return result;
}

int main() {
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;

    // Use the get_nums function to calculate the distribution of sk and sa - sk
    std::vector<int> ans_sk = get_nums(k, sk);
    std::vector<int> ans_sa_sk = get_nums(n - k, sa - sk);

    // Combine the results
    std::vector<int> ans;
    ans.insert(ans.end(), ans_sk.begin(), ans_sk.end());
    ans.insert(ans.end(), ans_sa_sk.begin(), ans_sa_sk.end());

    // Print the result as a space-separated string of numbers
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << ans[i];
    }
    std::cout << std::endl;

    return 0;
}
