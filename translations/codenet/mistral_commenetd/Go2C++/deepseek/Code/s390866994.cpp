#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Initialize variables
    int N, C, K;
    cin >> N >> C >> K;

    // Initialize vector t of size N
    vector<int> t(N);

    // Read input: t[i] for i from 0 to N-1
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    // Sort vector t in ascending order
    sort(t.begin(), t.end());

    // Initialize variables: answer counter ans, counter cnt, and end index end
    int ans = 1;
    int cnt = 1;
    int end = t[0] + K;

    // Iterate through vector t from index 1 to N-1
    for (int i = 1; i < N; i++) {
        // If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
        if (cnt < C && t[i] <= end) {
            cnt++;
        } else {
            // Reset counter cnt and update end index end to the current element t[i] plus K
            cnt = 1;
            end = t[i] + K;
            // Increment answer counter ans
            ans++;
        }
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
