#include <bits/stdc++.h>
using namespace std;

// Constants for modulo and limits
const int MOD = 1000000007;
const int MAX = INT_MAX;
const long long LMAX = LONG_MAX;

// Length for the array
int len = (int) 1e6 + 1;

void doIt() {
    // Read the number of elements N and the long value K
    int N = cin.get();
    long long K = cin.get();

    // Initialize the array A to store the input values
    int A[N];

    // Read N integers into the array A and adjust values to be zero-indexed
    for (int i = 0; i < N; i++) {
        A[i] = cin.get() - 1;
    }

    // Set to track used indices and arrays to store index and position
    set<int> used;
    int idx[N];
    int pos[N];

    // Initialize variables for the cycle detection
    int next = 0, cur = 0;

    // Detect the cycle in the array using the 'used' set
    while (!used.count(next)) {
        used.insert(next);
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }

    // Calculate the lengths of the cycle and the position of the next element
    long long a = (long long) cur - idx[next];
    long long b = (long long) idx[next];

    // Calculate the answer based on the cycle length and K
    int ans = (int) ((10000 * a + K - b) % a + b);

    // If b is greater than K, set ans to K
    if (b > K) ans = (int) K;

    // Output the result, adjusting for 1-based indexing
    cout << pos[ans] + 1 << endl;
}

int main() {
    // Create an instance of Main and call the doIt method
    doIt();
    return 0;
}

