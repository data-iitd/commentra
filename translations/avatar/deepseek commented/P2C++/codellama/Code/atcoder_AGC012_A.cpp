#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// Function to read integers from input
vector<int> readInts() {
    vector<int> A;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    return A;
}

// Function to calculate the sum of every second element from the end
int sumEverySecond(vector<int> A) {
    int ans = 0;
    for (int i = A.size() - 2; i >= A.size() - 2 * A.size() - 1; i -= 2) {
        ans += A[i];
    }
    return ans;
}

// Main function
int main() {
    vector<int> A = readInts();
    sort(A.begin(), A.end());
    int ans = sumEverySecond(A);
    cout << ans << endl;
    return 0;
}

// End of code
