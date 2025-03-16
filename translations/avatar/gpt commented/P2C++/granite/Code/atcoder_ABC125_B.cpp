
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    vector<int> profit_differences;
    profit_differences.push_back(0);

    int ans = 0;
    int X = 0;
    int Y = 0;

    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) {
            X = V[i];
            Y = C[i];
            profit_differences.push_back(X - Y);
        }
    }

    ans = accumulate(profit_differences.begin(), profit_differences.end(), 0);

    cout << ans << endl;

    return 0;
}
