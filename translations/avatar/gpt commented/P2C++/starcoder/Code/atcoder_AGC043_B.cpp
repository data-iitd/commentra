#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of factors of 2 in n!
int twos_in_factorial(int n) {
    int count = 0;
    while (n) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

// Function to determine the parity (even or odd) of the binomial coefficient C(n, i)
bool parity_of_nCr(int n, int i) {
    int f = twos_in_factorial(n);  // Reference to the function that calculates the number of factors of 2
    // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return f - twos_in_factorial(n - i) - twos_in_factorial(i) > 0;
}

int main() {
    int n;  // Read an integer n from input
    cin >> n;
    vector<int> nums;  // Read a list of integers, subtracting 1 from each input value
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num - 1);
    }
    
    bool no_one = false;  // Flag to check if there are no '1's in the input list
    if (find(nums.begin(), nums.end(), 1) == nums.end()) {
        // If there are no '1's, divide each number in nums by 2
        for (int i = 0; i < nums.size(); i++) {
            nums[i] /= 2;
        }
        no_one = true;  // Set the flag to True since there were no '1's

    bool is_odd = false;  // Flag to track if the overall parity is odd
    for (int i = 0; i < nums.size(); i++) {
        // Check the parity of C(n-1, i) and if num is odd
        if (!parity_of_nCr(n - 1, i) && nums[i] & 1) {
            is_odd ^= 1;  // Toggle the is_odd flag if the conditions are met
    }

    // Print the result based on the parity
    if (!is_odd) {
        cout << 0 << endl;  // If the overall parity is even, print 0
    } else {
        cout << (1 << no_one) << endl;  // If odd, print 1 or 2 based on the no_one flag
}

