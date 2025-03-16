#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<tuple<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> get<1>(A[i]);
        get<0>(A[i]) = i + 1;
    }

    sort(A.begin(), A.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
        return get<1>(a) < get<1>(b);
    });

    vector<int> A__(N);
    for (int i = 0; i < N; i++) {
        A__[i] = get<0>(A[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        cout << A__[i] << " ";
    }
    cout << A__[N - 1] << endl;

    return 0;
}

