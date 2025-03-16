
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].second;
        A[i].first = i + 1;
    }
    sort(A.begin(), A.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    for (int i = 0; i < N - 1; i++) {
        cout << A[i].first << " ";
    }
    cout << A[N - 1].first << endl;
    return 0;
}

