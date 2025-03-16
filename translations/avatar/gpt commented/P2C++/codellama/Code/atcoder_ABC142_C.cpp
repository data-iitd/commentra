#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push_back(make_pair(i + 1, x));
    }

    sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    vector<int> A_;
    for (int i = 0; i < N; i++) {
        A_.push_back(A[i].first);
    }

    for (int i = 0; i < N - 1; i++) {
        cout << A_[i] << " ";
    }
    cout << A_[N - 1] << endl;

    return 0;
}

