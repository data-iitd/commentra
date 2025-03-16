#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in the factorial of n
    int count = 0;
    while (n > 0) {
        count += n / 2;
        n /= 2;
    }
    return count;
}

bool parity_of_nCr(int n, int i) {
    // Determine the parity (odd or even) of the binomial coefficient nCr
    int f = twos_in_factorial(n) - twos_in_factorial(n - i) - twos_in_factorial(i);
    return f > 0;
}

int main() {
    // Read an integer n and a list of integers from the input
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        --nums[i];
    }
    
    // If the list does not contain the number 1, halve each number in the list and set no_one to true
    bool no_one = false;
    if (std::find(nums.begin(), nums.end(), 1) == nums.end()) {
        for (int &num : nums) {
            num /= 2;
        }
        no_one = true;
    }
    
    // Initialize is_odd to false
    bool is_odd = false;
    
    // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
    for (int i = 0; i < nums.size(); ++i) {
        if (!parity_of_nCr(n - 1, i) && nums[i] % 2 == 1) {
            is_odd ^= 1;
        }
    }
    
    // If is_odd is false, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
    if (!is_odd) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << (1 << no_one) << std::endl;
    }
    
    return 0;
}
