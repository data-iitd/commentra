
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class BIT {
private:
    int size;
    vector<int> tree;
    int depth;

public:
    // Initialize the Binary Indexed Tree (BIT) with size N
    BIT(int N) {
        size = N;  // Store the size of the BIT
        tree = vector<int>(N + 1, 0);  // Initialize the BIT array with zeros
        depth = N.bit_length();  // Calculate the depth of the BIT
    }

    // Internal method to calculate the prefix sum up to index i
    int _bitsum(int i) {
        int ret = 0;  // Initialize the sum
        while (i) {
            ret += tree[i];  // Add the value at index i to the sum
            i ^= i & -i;  // Move to the parent index
        }
        return ret;  // Return the calculated sum
    }

    // Public method to calculate the sum in the range [l, r]
    int bitsum(int l, int r = -1) {
        if (r == -1) {
            return _bitsum(l);  // If r is not provided, return the sum up to l
        } else {
            return _bitsum(r) - _bitsum(l);  // Return the sum in the range [l, r]
        }
    }

    // Method to add a value x at index i
    void bitadd(int i, int x) {
        i++;  // Adjust index to match BIT's 1-based indexing
        while (i <= size) {
            tree[i] += x;  // Update the BIT with the value x
            i += i & -i;  // Move to the next index
        }
    }
};

int main() {
    int n;
    cin >> n;  // Read the number of elements
    int m = n * (n + 1) / 4;  // Calculate the target value m based on the number of elements
    vector<int> a(n);  // Initialize the input array
    map<int, int> d;  // Dictionary to hold the mapping of values to their indices
    vector<int> _a;  // List to hold the sorted list of unique values from a, including 0

    // Read the input array and convert it to a list of integers
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        _a.push_back(a[i]);
    }
    // Sort the list of unique values from a, including 0
    sort(_a.begin(), _a.end());
    _a.erase(unique(_a.begin(), _a.end()), _a.end());

    // Map original values to their indices in the sorted list
    for (int i = 0; i < _a.size(); i++) {
        d[_a[i]] = i;
    }
    // Replace original values in a with their corresponding indices
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }

    // Function to check if a certain value X can be achieved
    function<bool(int)> check = [&](int X) {
        vector<int> b(n + 1, 0);  // Initialize a new list b where each element indicates if the corresponding a[i] is >= X
        for (int i = 0; i < n; i++) {
            b[i + 1] += (a[i] >= X) * 2 - 1;  // Update b based on the condition
        }
        for (int i = 1; i <= n; i++) {
            b[i] += b[i - 1];  // Calculate the prefix sums of b
        }
        int c = *min_element(b.begin(), b.end());  // Find the minimum value in b
        for (int i = 0; i <= n; i++) {
            b[i] -= c;  // Normalize b by subtracting the minimum value
        }
        BIT bit(max(b) + 2);  // Initialize a BIT for the range of b
        int ans = 0;  // Initialize the answer counter
        for (int i = 0; i <= n; i++) {
            ans += bit.bitsum(b[i] + 1);  // Count how many indices have been added that are less than b[i]
            bit.bitadd(b[i], 1);  // Add the current index to the BIT
        }
        return ans >= m;  // Return whether the count is at least m
    };

    // Initialize the binary search bounds
    int t[2] = {static_cast<int>(_a.size()), 0};
    // Perform binary search to find the maximum value that satisfies the condition
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;  // Calculate the midpoint
        t[check(mid)] = mid;  // Update the bounds based on the check function
    }

    // Print the result corresponding to the found index
    cout << _a[t[1]] << endl;  // Print the maximum value that satisfies the condition

    return 0;
}

