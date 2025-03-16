
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = A.size() - 2; i >= A.size() - 2 * n - 1; i -= 2) {
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}

