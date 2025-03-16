#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Function to compute the cumulative sum of a vector of integers
vector<int> CumSum(const vector<int>& nums) {
    vector<int> sums = {0};
    for (int num : nums) {
        sums.push_back(sums.back() + num);
    }
    return sums;
}

// Function to compute the absolute value of an integer
int Abs(int a) {
    return (a >= 0) ? a : -a;
}

// Function to compute the minimum of a list of integers
int Min(const vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
}

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Create a vector to hold the input integers
    vector<int> aa(n);

    // Read each integer and store it in the vector
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }

    // Compute the cumulative sum of the input integers
    vector<int> cumsum = CumSum(aa);

    // Initialize the answer with a large value
    int ans = numeric_limits<int>::max();

    // Iterate through the cumulative sums to find the minimum difference
    for (int i = 1; i < cumsum.size() - 1; i++) {
        ans = Min({ans, Abs(cumsum.back() - cumsum[i] - (cumsum[i] - cumsum[0]))});
    }

    // Output the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
