#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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
    copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
    cout << A.back().first << endl;
    return 0;
}

