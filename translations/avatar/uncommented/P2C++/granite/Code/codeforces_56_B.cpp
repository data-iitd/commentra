
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int mn = N + 1, mx = -1;
    for (int i = 0; i < N; i++) {
        if (i + 1!= A[i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if (mx == -1) {
        cout << "0 0" << endl;
    } else {
        rotate(A.begin(), A.begin() + mn, A.end());
        bool sorted = true;
        for (int i = 0; i < N; i++) {
            if (i + 1!= A[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            cout << mn + 1 << " " << mx + 1 << endl;
        } else {
            cout << "0 0" << endl;
        }
    }
    return 0;
}
