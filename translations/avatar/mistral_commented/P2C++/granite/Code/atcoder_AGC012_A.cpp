
#####
#include <bits/stdc++.h>
using namespace std;

#####
// Function to read integers from the standard input
#####

vector<int> readInts() {
    // Reads a list of integers from the standard input.
    vector<int> A;
    int n;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    return A;
}

#####
// Main function
#####

int main() {
    // Reads the number of integers 'n' and a list 'A' of 'n' integers from the standard input.
    // Sorts the list 'A' in ascending order.
    // Calculates the answer by summing up the elements of 'A' at indices which are not multiples of '2n+1'.
    // Prints the answer.
    int n;
    cin >> n;
    vector<int> A = readInts();
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = A.size() - 2; i >= A.size() - 2 * n - 1; i -= 2) {
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}

