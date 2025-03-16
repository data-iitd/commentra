#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main() {
    // Ask the user for the size of the permutation list
    int n;
    cin >> n;

    // Create a vector of all possible permutations of numbers from 1 to n
    vector<vector<int>> orig;
    for (int i = 1; i <= n; i++) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        do {
            orig.push_back(v);
        } while (next_permutation(v.begin(), v.end()));
    }

    // Ask the user for two permutations as tuples
    vector<int> p, q;
    cin >> p >> q;

    // Find the indices of p and q in the orig vector
    int pn = distance(orig.begin(), find(orig.begin(), orig.end(), p));
    int qn = distance(orig.begin(), find(orig.begin(), orig.end(), q));

    // Print the absolute difference between the indices of p and q
    cout << abs(pn - qn) << endl;

    return 0;
}

