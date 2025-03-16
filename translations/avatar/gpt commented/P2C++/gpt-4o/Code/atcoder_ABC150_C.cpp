#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

// Function to generate all permutations of a vector
void generatePermutations(vector<int>& nums, vector<vector<int>>& result, int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, result, start + 1);
        swap(nums[start], nums[i]); // backtrack
    }
}

int main() {
    // Read an integer input n
    int n;
    cin >> n;

    // Generate numbers from 1 to n
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    // Generate all possible permutations
    vector<vector<int>> orig;
    generatePermutations(numbers, orig, 0);

    // Read the first permutation input
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Read the second permutation input
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    // Find the indices of the permutations
    int pn = find(orig.begin(), orig.end(), p) - orig.begin();
    int qn = find(orig.begin(), orig.end(), q) - orig.begin();

    // Calculate and print the absolute difference between the two indices
    cout << abs(pn - qn) << endl;

    return 0;
}

// <END-OF-CODE>
