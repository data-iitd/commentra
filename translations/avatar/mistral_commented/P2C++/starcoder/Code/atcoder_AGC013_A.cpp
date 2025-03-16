#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if (A[i - 1] < A[i] > A[i + 1] || A[i - 1] > A[i] < A[i + 1]) {
            ans++;
            i++;
        }
    }

    i++;
    cout << ans + 1 << endl;

    return 0;
}

