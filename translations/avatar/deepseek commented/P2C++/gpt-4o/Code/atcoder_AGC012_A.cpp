#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read integers from input
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
    cin >> n;  // Read integer n
    vector<int> A = readInts();  // Read list A
    sort(A.begin(), A.end());  // Sort the list A
    long long ans = 0;  // Initialize answer variable
    
    // Calculate the sum of every second element from the end
    for (int i = A.size() - 2; i >= A.size() - 2 * n; i -= 2) {
        ans += A[i];
    }
    
    cout << ans << endl;  // Print the calculated sum
    return 0;
}

// <END-OF-CODE>
