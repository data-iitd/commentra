#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    return n - bitset<32>(n).count();
}

bool parity_of_nCr(int n, int i) {
    // Determine the parity (even or odd) of the binomial coefficient C(n, i)
    int f_n = twos_in_factorial(n);
    int f_n_i = twos_in_factorial(n - i);
    int f_i = twos_in_factorial(i);
    // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return f_n - f_n_i - f_i > 0;
}

int main() {
    // Read an integer n from input
    int n;
    cin >> n;
    
    // Read a list of integers, subtracting 1 from each input value
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num - 1);
    }

    bool no_one = false;  // Flag to check if there are no '1's in the input list
    if (find(nums.begin(), nums.end(), 1) == nums.end()) {
        // If there are no '1's, divide each number in nums by 2
        for (auto& n : nums) {
            n /= 2;
        }
        no_one = true;  // Set the flag to True since there were no '1's
    }

    bool is_odd = false;  // Flag to track if the overall parity is odd
    for (size_t i = 0; i < nums.size(); ++i) {
        // Check the parity of C(n-1, i) and if num is odd
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            is_odd ^= 1;  // Toggle the is_odd flag if the conditions are met
        }
    }

    // Print the result based on the parity
    if (!is_odd) {
        cout << 0 << endl;  // If the overall parity is even, print 0
    } else {
        cout << (1 << no_one) << endl;  // If odd, print 1 or 2 based on the no_one flag
    }

    return 0;
}

// <END-OF-CODE>
