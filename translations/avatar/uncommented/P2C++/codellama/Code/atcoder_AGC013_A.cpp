
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A = vector<int>(A.begin(), unique(A.begin(), A.end()));
    N = A.size();
    int i = 1;
    int ans = 0;
    while (i < N - 1) {
        if (A[i - 1] < A[i] > A[i + 1] || A[i - 1] > A[i] < A[i + 1]) {
            ans++;
            i++;
        }
        i++;
    }
    cout << ans + 1 << endl;
    return 0;
}

