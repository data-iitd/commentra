

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 1000000
#define LMAX 100000000000000000

void doIt() {
    // Read the number of elements N and the value K
    int N, K;
    cin >> N >> K;

    // Read the array A with N elements, adjusting each element by -1 for 0-based indexing
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    // Set to track visited indices
    set<int> used;

    // Arrays to store index and position information
    vector<int> idx(N);
    vector<int> pos(N);

    // Initialize variables for cycle detection
    int next = 0, cur = 0;

    // Detect the cycle in the array A
    while (!used.count(next)) {
        used.insert(next);
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }

    // Calculate the length of the cycle and adjust the position based on K
    long long a = (long long)cur - idx[next];
    long long b = (long long)idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);

    // Adjust the answer if necessary based on the cycle length
    if (b > K) ans = K;

    // Output the final position
    cout << pos[ans] + 1 << endl;
}

int main() {
    doIt();
    return 0;
}

