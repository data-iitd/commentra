#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>

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
    vector<int> A_(N);
    transform(A.begin(), A.end(), A_.begin(), [](pair<int, int> a) {
        return a.first;
    });
    copy(A_.begin(), A_.end() - 1, ostream_iterator<int>(cout, " "));
    cout << A_[N - 1] << endl;
    return 0;
}

