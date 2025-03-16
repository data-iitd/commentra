#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Function to read an integer from standard input
int getInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read an array of integers from standard input
vector<int> getIntSlice(int n) {
    vector<int> is(n);
    for (int i = 0; i < n; ++i) {
        is[i] = getInt();
    }
    return is;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Main function of the program
int main() {
    // Get the number of elements in the input array
    int n = getInt();
    // Get the input array
    vector<int> ls = getIntSlice(n);
    // Create a reversed copy of the input array
    vector<int> lsRev = ls;
    // Sort the input array in ascending order
    sort(ls.begin(), ls.end());
    // Sort the reversed copy of the array in descending order
    sort(lsRev.rbegin(), lsRev.rend());

    // Initialize the answer variable
    long long ans = 0;
    // Iterate through all pairs of elements in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Find the minimum and maximum elements of the current pair
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the difference between the maximum and minimum elements
            int x = q - p;
            int y = q + p;
            // Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
            int l = lower_bound(ls.begin(), ls.end(), x + 1) - ls.begin();
            int r = n - (upper_bound(lsRev.begin(), lsRev.end(), y - 1) - lsRev.begin());
            // Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
            long long sum = r - l;
            // Check if the current pair lies within the range [l, r]
            if (i >= l && i <= r) {
                sum--;
            }
            if (j >= l && j <= r) {
                sum--;
            }
            // Ensure that the sum is not negative
            sum = max(0LL, sum);
            // Add the sum to the answer variable
            ans += sum;
        }
    }
    // Divide the answer by 3 and print it
    ans /= 3;
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
