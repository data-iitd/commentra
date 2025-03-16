#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Function to get an integer from standard input
int getInt() {
    int n;
    cin >> n;
    return n;
}

// Function to get a vector of integers from standard input
vector<int> getIntVector(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    return vec;
}

// Function to get a string from standard input
string getString() {
    string s;
    cin >> s;
    return s;
}

// Function to print the given arguments followed by a newline
void puts(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
void mainFn() {
    // Get the number of elements in the input array
    int n = getInt();
    // Get the input array
    vector<int> ls = getIntVector(n);
    // Create a reversed copy of the input array
    vector<int> lsRev(ls);
    // Sort the input array in ascending order
    sort(ls.begin(), ls.end());
    // Sort the reversed copy of the array in descending order
    sort(lsRev.begin(), lsRev.end(), greater<int>());

    // Initialize the answer variable
    int ans = 0;
    // Iterate through all pairs of elements in the array
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Find the minimum and maximum elements of the current pair
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the difference between the maximum and minimum elements
            int x = q - p;
            int y = q + p;
            // Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
            int l = distance(ls.begin(), lower_bound(ls.begin(), ls.end(), x));
            int r = n - distance(lsRev.begin(), lower_bound(lsRev.begin(), lsRev.end(), y, greater<int>()));
            // Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
            int sum = r - l;
            // Check if the current pair lies within the range [l, r]
            if (i >= l && i <= r) {
                --sum;
            }
            if (j >= l && j <= r) {
                --sum;
            }
            // Ensure that the sum is not negative
            sum = max(0, sum);
            // Add the sum to the answer variable
            ans += sum;
        }
    }
    // Divide the answer by 3 and print it
    ans /= 3;
    cout << ans << endl;
}

int main() {
    // Call the main function
    mainFn();
    return 0;
}
