#include <iostream>
#include <vector>
#include <string>

std::vector<int> get_nums(int num, int t) {
    // This function distributes the value t among num parts.
    std::vector<int> result(num);
    int base = t / num;
    int extra = t % num;

    for (int i = 0; i < num; ++i) {
        result[i] = base + (i < extra ? 1 : 0);
    }
    return result;
}

int main() {
    // Read input values for n, k, l, r, sa, and sk
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;

    // Use the get_nums function to calculate the distribution of sk and sa - sk
    std::vector<int> ans = get_nums(k, sk);
    std::vector<int> remaining = get_nums(n - k, sa - sk);
    
    // Combine the results
    ans.insert(ans.end(), remaining.begin(), remaining.end());

    // Print the result as a space-separated string of numbers
    for (size_t i = 0; i < ans.size(); ++i) {
        std::cout << ans[i];
        if (i < ans.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
