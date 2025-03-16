#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto na = []() {
        int n, x;
        cin >> n >> x;
        return make_pair(n, x);
    };
    // Define a lambda function to read input and return n and x

    auto inputList = []() {
        int size;
        cin >> size;
        vector<int> vec(size);
        for (int &val : vec) {
            cin >> val;
        }
        return vec;
    };
    // Define a lambda function to read a list of integers

    auto [n, x] = na();
    // Read the values of n and x from input

    vector<int> a = inputList();
    sort(a.begin(), a.end());
    // Read the list `a` from input, then sort it in ascending order

    int ans = 0;
    // Initialize the variable `ans` to store the result

    if (a[0] > x) {
        cout << 0 << endl;
        return 0;
    }
    // Check if the smallest element in the sorted list `a` is greater than `x`. If so, print 0 and exit.

    for (int i : a) {
        if (i > x) {
            x = 0;
            break;
        }
        x -= i;
        ans++;
    }
    // Iterate through each element in the sorted list `a`, subtracting each element from `x` and incrementing `ans` until `x` becomes 0 or an element greater than `x` is encountered.

    if (x != 0) {
        ans--;
    }
    // If `x` is not 0 after the loop, decrement `ans` by 1.

    cout << ans << endl;
    // Print the value of `ans`.

    return 0;
}
// <END-OF-CODE>
