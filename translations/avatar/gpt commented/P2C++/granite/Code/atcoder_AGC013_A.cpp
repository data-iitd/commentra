
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> B;
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i]!= A[i - 1]) {
            B.push_back(A[i]);
        }
    }

    N = B.size();
    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if ((B[i - 1] < B[i] && B[i] > B[i + 1]) || (B[i - 1] > B[i] && B[i] < B[i + 1])) {
            ans++;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}

