#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in the factorial of n
    return n - bitset<32>(n).count();
}

bool parity_of_nCr(int n, int i) {
    // Determine the parity (odd or even) of the binomial coefficient nCr
    int f = twos_in_factorial(n);
    return f - twos_in_factorial(n - i) - twos_in_factorial(i) > 0;
}

int main() {
    // Read an integer n and a list of integers from the input
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num - 1);
    }

    // If the list does not contain the number 1, halve each number in the list and set no_one to true
    bool no_one = false;
    if (find(nums.begin(), nums.end(), 1) == nums.end()) {
        for (auto &n : nums) {
            n /= 2;
        }
        no_one = true;
    }

    // Initialize is_odd to false
    bool is_odd = false;

    // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
    for (size_t i = 0; i < nums.size(); ++i) {
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            is_odd ^= 1;
        }
    }

    // If is_odd is false, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
    if (!is_odd) {
        cout << 0 << endl;
    } else {
        cout << (1 << no_one) << endl;
    }

    return 0;
}

// <END-OF-CODE>
