

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input representing the length of the list `a`
    vector<int> a(n);  // Initialize a vector `a` of length `n`
    for (int i = 0; i < n; i++) {
        cin >> a[i];  // Take an integer input and assign it to the `i`-th element of `a`
    }
    vector<int> b(n);  // Initialize an empty vector `b` of length `n`

    // Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;
    }

    int res = 0;  // Initialize the result variable `res` to 0

    // Calculate the sum of absolute differences between the positions of consecutive elements in `b`
    for (int i = 1; i < n; i++) {
        res += abs(b[i] - b[i - 1]);
    }

    cout << res << endl;  // Print the result

    return 0;
}
