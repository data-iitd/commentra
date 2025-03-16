

#include <iostream>  // Include the iostream library
#include <algorithm>  // Include the algorithm library
#include <vector>  // Include the vector library
using namespace std;  // Use the standard namespace
int main() {
    int n;  // Declare an integer variable `n`
    cin >> n;  // Take an integer input `n`
    vector<int> orig(n);  // Create a vector of size `n` to store the original numbers
    for (int i = 0; i < n; i++) {
        orig[i] = i + 1;  // Initialize the vector with numbers from 1 to `n`
    }
    vector<int> p(n), q(n);  // Declare two vectors `p` and `q` to store the permutations
    for (int i = 0; i < n; i++) {
        cin >> p[i];  // Take the first permutation `p` as a vector of integers
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];  // Take the second permutation `q` as a vector of integers
    }
    sort(orig.begin(), orig.end());  // Sort the vector `orig` in ascending order
    sort(p.begin(), p.end());  // Sort the vector `p` in ascending order
    sort(q.begin(), q.end());  // Sort the vector `q` in ascending order
    int pn = distance(orig.begin(), find(orig.begin(), orig.end(), p[0]));  // Find the index of permutation `p` in the sorted vector `orig`
    int qn = distance(orig.begin(), find(orig.begin(), orig.end(), q[0]));  // Find the index of permutation `q` in the sorted vector `orig`
    cout << abs(pn - qn) << endl;  // Calculate the absolute difference between the indices and print the result
    return 0;  // Return 0 to indicate successful execution
}
