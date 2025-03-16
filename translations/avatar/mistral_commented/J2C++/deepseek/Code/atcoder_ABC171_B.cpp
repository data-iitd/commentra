#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    // Initialize input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input: number of elements n and the number of summands k
    int n, k;
    cin >> n >> k;

    // Read input array a of size n
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array a using std::sort()
    sort(a.begin(), a.end());

    // Calculate the answer: sum of first k elements of sorted array a
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }

    // Write the answer to the output stream
    cout << ans << '\n';

    return 0;
}
