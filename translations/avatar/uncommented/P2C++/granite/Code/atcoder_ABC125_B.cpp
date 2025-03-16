
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<int> list;
    list.push_back(0);
    int ans = 0;
    int X = 0;
    int Y = 0;
    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) {
            X = V[i];
            Y = C[i];
            list.push_back(X - Y);
        }
    }
    ans = accumulate(list.begin(), list.end(), 0);
    cout << ans << endl;
    return 0;
}

