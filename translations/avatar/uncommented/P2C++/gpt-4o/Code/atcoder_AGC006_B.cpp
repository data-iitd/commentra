#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sub(vector<int> y, int debug = 0) {
    if (debug) {
        cout << "D ";
        for (int val : y) cout << val << " ";
        cout << endl;
    }
    while (y.size() > 1) {
        vector<int> new_y;
        for (size_t i = 0; i < y.size() - 2; ++i) {
            vector<int> temp = {y[i], y[i + 1], y[i + 2]};
            sort(temp.begin(), temp.end());
            new_y.push_back(temp[1]);
        }
        y = new_y;
        if (debug) {
            cout << "D ";
            for (int val : y) cout << val << " ";
            cout << endl;
        }
    }
    return y;
}

int main() {
    int N, X;
    cin >> N >> X;

    if (X == 1 || X == N * 2 - 1) {
        cout << "No" << endl;
    } else {
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
            for (int i = X + 3; i < N * 2; ++i) {
                ys.push_back(i);
            }
            xs.insert(xs.end(), ys.begin(), ys.begin() + (N - 3));
            xs.push_back(X + 2);
            xs.push_back(X - 1);
            xs.push_back(X);
            xs.push_back(X + 1);
            xs.insert(xs.end(), ys.begin() + (N - 3), ys.end());
        }
        for (int x : xs) {
            cout << x << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
