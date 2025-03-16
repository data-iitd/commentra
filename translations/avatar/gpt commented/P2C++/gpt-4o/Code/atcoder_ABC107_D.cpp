#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class BIT {
public:
    // Initialize the Binary Indexed Tree (BIT) with size N
    BIT(int N) : size(N), tree(N + 1, 0) {}

    // Internal method to calculate the prefix sum up to index i
    int bitsum(int i) {
        int ret = 0;  // Initialize the sum
        while (i) {
            ret += tree[i];  // Add the value at index i to the sum
            i ^= i & -i;  // Move to the parent index
        }
        return ret;  // Return the calculated sum
    }

    // Public method to calculate the sum in the range [l, r]
    int bitsum(int l, int r) {
        return bitsum(r) - bitsum(l);  // Return the sum in the range [l, r]
    }

    // Method to add a value x at index i
    void bitadd(int i, int x) {
        i += 1;  // Adjust index to match BIT's 1-based indexing
        while (i <= size) {
            tree[i] += x;  // Update the BIT with the value x
            i += i & -i;  // Move to the next index
        }
    }

private:
    int size;  // Store the size of the BIT
    vector<int> tree;  // Initialize the BIT array with zeros
};

// Function to check if a certain value X can be achieved
bool check(int X, const vector<int>& a, int n, int m) {
    vector<int> b(n + 1);
    b[0] = 0;
    for (int i = 0; i < n; ++i) {
        b[i + 1] = (a[i] >= X) ? 1 : -1;  // 1 if a[i] >= X, else -1
        b[i + 1] += b[i];  // Calculate prefix sums
    }
    int c = *min_element(b.begin(), b.end());  // Find the minimum value in b
    for (int i = 0; i <= n; ++i) {
        b[i] -= c;  // Normalize b by subtracting the minimum value
    }
    BIT bit(*max_element(b.begin(), b.end()) + 2);  // Initialize a BIT for the range of b
    int ans = 0;  // Initialize the answer counter
    // Count the number of valid pairs using the BIT
    for (int x : b) {
        ans += bit.bitsum(x + 1);  // Count how many indices have been added that are less than x
        bit.bitadd(x, 1);  // Add the current index to the BIT
    }
    return ans >= m;  // Return whether the count is at least m
}

int main() {
    // Read the number of elements
    int n;
    cin >> n;
    // Calculate the target value m based on the number of elements
    int m = n * (n + 1) / 4;
    // Read the input array and convert it to a vector of integers
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_map<int, int> d;  // Dictionary to hold the mapping of values to their indices
    vector<int> _a = a;  // Create a copy of a
    _a.push_back(0);  // Include 0 in the sorted list
    sort(_a.begin(), _a.end());
    _a.erase(unique(_a.begin(), _a.end()), _a.end());  // Remove duplicates

    // Map original values to their indices in the sorted list
    for (int i = 0; i < _a.size(); ++i) {
        d[_a[i]] = i;
    }
    // Replace original values in a with their corresponding indices
    for (int i = 0; i < n; ++i) {
        a[i] = d[a[i]];
    }

    // Initialize the binary search bounds
    int left = 0, right = _a.size();
    // Perform binary search to find the maximum value that satisfies the condition
    while (right - left > 1) {
        int mid = (left + right) / 2;  // Calculate the midpoint
        if (check(_a[mid], a, n, m)) {
            left = mid;  // Update the bounds based on the check function
        } else {
            right = mid;  // Update the bounds based on the check function
        }
    }

    // Print the result corresponding to the found index
    cout << _a[left] << endl;

    return 0;
}

// <END-OF-CODE>
