#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read integers from the standard input
vector<int> readInts() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    return nums;
}

// Main function
int main() {
    int n;
    cin >> n;
    vector<int> A = readInts();
    
    // Sort the list A in ascending order
    sort(A.begin(), A.end());
    
    long long ans = 0; // Use long long to avoid overflow
    // Calculate the answer by summing up the elements of A at indices which are not multiples of 2n + 1
    for (int i = A.size() - 2; i >= A.size() - 2 * n; i -= 2) {
        ans += A[i];
    }
    
    cout << ans << endl; // Print the answer
    return 0;
}

// <END-OF-CODE>
