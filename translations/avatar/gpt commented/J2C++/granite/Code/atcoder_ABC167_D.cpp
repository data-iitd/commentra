
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MOD = 1000000007;
const int MAX = INT_MAX;
const long LMAX = LLONG_MAX;

int main() {
    // Initialize scanner for input
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Constants for modulo and limits
    const int MOD = 1000000007;
    const int MAX = INT_MAX;
    const long LMAX = LLONG_MAX;

    // Length for the array
    int len = (int) 1e6 + 1;

    int N, K;
    cin >> N >> K;

    // Initialize the array A to store the input values
    vector<int> A(N);

    // Read N integers into the array A and adjust values to be zero-indexed
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    // Set to track used indices and arrays to store index and position
    set<int> used;
    vector<int> idx(N);
    vector<int> pos(N);

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
    long a = (long) cur - idx[next];
    long b = (long) idx[next];

    // Calculate the answer based on the cycle length and K
    int ans = (int) ((10000 * a + K - b) % a + b);

    // If b is greater than K, set ans to K
    if (b > K) ans = (int) K;

    // Output the result, adjusting for 1-based indexing
    cout << pos[ans] + 1 << endl;

    return 0;
}

