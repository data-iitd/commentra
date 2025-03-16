#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int A[N];
    for (int n = 0; n < N; n++) {
        cin >> A[n];
    }
    sort(A, A + N);
    int min = A[0];
    int max = A[N - 1];
    long mins = 0;
    long maxs = 0;
    for (int value : A) {
        if (value == min) mins++;
        if (value == max) maxs++;
    }
    if (min == max) {
        cout << (max - min) << " " << mins * (mins - 1) / 2 << "\n";
    } else {
        cout << (max - min) << " " << mins * maxs << "\n";
    }
    return 0;
}

