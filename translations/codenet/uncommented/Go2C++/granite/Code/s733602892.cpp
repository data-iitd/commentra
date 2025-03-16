
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), F(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }
    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        scores[i] = A[i] * F[i];
    }
    sort(scores.rbegin(), scores.rend());
    int ok = scores[0], ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        bool isOK = true;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (A[i] * F[i] > mid) {
                k -= A[i] - mid / F[i];
            }
            if (k < 0) {
                isOK = false;
            }
        }
        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}

