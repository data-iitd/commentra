#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int twos_in_factorial(int n) {
    return n - bitset<32>(n).count(); // Assuming 32 bits for the bitset
}

bool parity_of_nCr(int n, int i) {
    int f_n = twos_in_factorial(n);
    int f_n_minus_i = twos_in_factorial(n - i);
    int f_i = twos_in_factorial(i);
    return (f_n - f_n_minus_i - f_i) > 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num - 1);
    }

    bool no_one = false;
    if (find(nums.begin(), nums.end(), 1) == nums.end()) {
        for (auto &num : nums) {
            num /= 2;
        }
        no_one = true;
    }

    bool is_odd = false;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            is_odd ^= 1;
        }
    }

    if (!is_odd) {
        cout << 0 << endl;
    } else {
        cout << (1 << no_one) << endl;
    }

    return 0;
}

// <END-OF-CODE>
