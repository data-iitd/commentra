#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Function to compute the cumulative sum of a vector
vector<int> CumSum(const vector<int>& nums) {
    vector<int> sums = {0};
    for (int num : nums) {
        sums.push_back(sums.back() + num);
    }
    return sums;
}

// Function to compute the absolute value
int Abs(int a) {
    return a >= 0 ? a : -a;
}

// Function to compute the minimum of multiple integers
int Min(const vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
}

int main() {
    // Read the number n from the standard input
    int n;
    cin >> n;

    // Initialize a vector to store the input integers
    vector<int> aa(n);
    
    // Read n integers from the standard input
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }

    // Compute the cumulative sum of the aa vector
    vector<int> cumsum = CumSum(aa);

    // Initialize a variable ans to store the answer
    int ans = numeric_limits<int>::max();

    // Iterate through the cumulative sum array, excluding the first and last elements
    for (int i = 1; i < cumsum.size() - 1; i++) {
        // Compute the absolute difference between the last cumulative sum and the current cumulative sum
        int diff1 = Abs(cumsum.back() - cumsum[i]);

        // Compute the difference between the current cumulative sum and the first cumulative sum
        int diff2 = cumsum[i] - cumsum[0];

        // Keep the minimum of these two differences as the answer
        ans = Min({ans, diff1, diff2});
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
