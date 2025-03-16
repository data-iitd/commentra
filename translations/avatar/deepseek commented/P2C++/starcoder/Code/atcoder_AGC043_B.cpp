#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    // Read an integer n and a list of integers from the input
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num - 1);
    }
    
    // If the list does not contain the number 1, halve each number in the list and set no_one to True
    bool no_one = false;
    if (nums.end() == find(nums.begin(), nums.end(), 0)) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] /= 2;
        }
        no_one = true;
    }
    
    // Initialize is_odd to False
    bool is_odd = false;
    
    // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
    for (int i = 0; i < nums.size(); i++) {
        if (!parity_of_nCr(n - 1, i) && nums[i] & 1) {
            is_odd ^= 1;
        }
    }
    
    // If is_odd is False, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
    if (!is_odd) {
        cout << 0 << endl;
    } else {
        cout << (1 << no_one) << endl;
    }
    
    return 0;
}

bool parity_of_nCr(int n, int i) {
    // Determine the parity (odd or even) of the binomial coefficient nCr
    int f = twos_in_factorial(n);
    return f - twos_in_factorial(n - i) - twos_in_factorial(i) > 0;
}

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in the factorial of n
    string s = to_string(n);
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            count++;
        }
    }
    return n - count;
}

