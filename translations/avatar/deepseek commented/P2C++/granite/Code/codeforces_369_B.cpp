
#include <iostream>
#include <vector>

std::vector<int> get_nums(int num, int t) {
    // This function distributes the value t among num parts.
    // It calculates the base number for each part by dividing t by num.
    // It adds 1 to the base number for the first t % num parts.
    std::vector<int> ans;
    for (int i = 0; i < num; i++) {
        ans.push_back(t / num + (i < t % num));
    }
    return ans;
}

int main() {
    // Read input values for n, k, l, r, sa, and sk
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;

    // Use the get_nums function to calculate the distribution of sk and sa - sk
    std::vector<int> ans = get_nums(k, sk) + get_nums(n - k, sa - sk);

    // Print the result as a space-separated string of numbers
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << (i == ans.size() - 1? "\n" : " ");
    }

    return 0;
}

