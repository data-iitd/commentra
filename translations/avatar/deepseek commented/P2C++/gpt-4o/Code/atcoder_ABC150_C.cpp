#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input `n`
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;  // Create a vector with numbers from 1 to `n`
    }

    vector<vector<int>> orig;  // To store all permutations
    do {
        orig.push_back(nums);  // Add the current permutation to the list
    } while (next_permutation(nums.begin(), nums.end()));  // Generate the next permutation

    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];  // Take the first permutation `p`
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i];  // Take the second permutation `q`
    }

    // Find the indices of permutations `p` and `q`
    auto pn = find(orig.begin(), orig.end(), p) - orig.begin();
    auto qn = find(orig.begin(), orig.end(), q) - orig.begin();

    cout << abs(pn - qn) << endl;  // Calculate the absolute difference and print the result

    return 0;
}  // <END-OF-CODE>
