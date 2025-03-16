
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C, K;
    cin >> N >> C >> K;

    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int ans = 1, cnt = 1, end = t[0] + K;
    for (int i = 1; i < N; i++) {
        if (cnt < C && t[i] <= end) {
            cnt++;
        } else {
            cnt = 1;
            end = t[i] + K;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

