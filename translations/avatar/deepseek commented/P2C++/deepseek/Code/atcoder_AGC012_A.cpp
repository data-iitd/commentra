#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

using namespace std;

// Function to read integers from input
vector<int> readInts() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
    }
    return A;
}

// Main function
void main() {
    int n;
    cin >> n;
    vector<int> A = readInts();
    sort(A.begin(), A.end());
    int ans = 0;

    // Calculate the sum of every second element from the end
    for (int i = A.size() - 2; i >= A.size() - 2 * n - 1; i -= 2) {
        ans += A[i];
    }

    cout << ans << endl;
}

