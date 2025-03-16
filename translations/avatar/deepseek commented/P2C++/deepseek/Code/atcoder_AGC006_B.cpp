#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    if (X == 1 || X == N * 2 - 1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    vector<int> xs;

    if (X == N * 2 - 2) {
        for (int i = N - 1; i <= X + 1; ++i) {
            xs.push_back(i);
        }
        for (int i = 1; i < N - 1; ++i) {
            xs.push_back(i);
        }
    } else {
        vector<int> ys;
        for (int i = 1; i < X - 1; ++i) {
            ys.push_back(i);
        }
        for (int i = X + 3; i <= N * 2; ++i) {
            ys.push_back(i);
        }
        for (int i = 0; i < N - 3; ++i) {
            xs.push_back(ys[i]);
        }
        xs.push_back(X + 2);
        xs.push_back(X - 1);
        xs.push_back(X);
        xs.push_back(X + 1);
        for (int i = N - 3; i < ys.size(); ++i) {
            xs.push_back(ys[i]);
        }
    }

    for (int x : xs) {
        cout << x << endl;
    }

    return 0;
}

