#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int twos_in_factorial(int n) {
    std::string binary = std::bitset<32>(n).to_string();
    binary.erase(0, binary.find_first_not_of('0'));
    return n - std::count(binary.begin(), binary.end(), '1');
}

bool parity_of_nCr(int n, int i) {
    int f = twos_in_factorial(n) - twos_in_factorial(n - i) - twos_in_factorial(i);
    return f > 0;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int &num : nums) {
        std::cin >> num;
        num--;
    }

    bool no_one = false;
    if (std::find(nums.begin(), nums.end(), 1) == nums.end()) {
        for (int &num : nums) {
            num /= 2;
        }
        no_one = true;
    }

    bool is_odd = false;
    for (int i = 0; i < nums.size(); ++i) {
        if (!parity_of_nCr(n - 1, i) && nums[i] % 2 == 1) {
            is_odd ^= 1;
        }
    }

    if (!is_odd) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << (1 << no_one) << std::endl;
    }

    return 0;
}
