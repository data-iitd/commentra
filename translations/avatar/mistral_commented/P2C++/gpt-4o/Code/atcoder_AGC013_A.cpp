#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// Function to read an integer from standard input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from standard input
vector<int> readList(int n) {
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    return A;
}

int main() {
    // Set input parameters and initialize variables
    int N = readInt();
    vector<int> A = readList(N);

    // Remove consecutive duplicates
    vector<int> uniqueA;
    unique_copy(A.begin(), A.end(), back_inserter(uniqueA));
    A = uniqueA;

    N = A.size();
    int i = 1;
    int ans = 0;

    // Main logic
    while (i < N - 1) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans += 1;
            i += 1;
        }
        i++;
    }

    cout << ans + 1 << endl; // Print the final answer

    return 0;
}
// <END-OF-CODE>
