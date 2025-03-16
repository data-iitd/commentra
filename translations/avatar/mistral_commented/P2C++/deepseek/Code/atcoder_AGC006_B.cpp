#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int calc(int x) {
    auto sub = [](int y, bool debug = false) {
        if (debug) {
            cout << "D " << y << endl;
        }
        while (y.size() > 1) {
            vector<int> temp;
            for (size_t i = 0; i <= y.size() - 3; ++i) {
                vector<int> sub_vec(y.begin() + i, y.begin() + i + 3);
                sort(sub_vec.begin(), sub_vec.end());
                temp.push_back(sub_vec[1]);
            }
            y = temp;
            if (debug) {
                cout << "D ";
                for (int val : y) {
                    cout << val << " ";
                }
                cout << endl;
            }
        }
        return y[0];
    };

    vector<int> y = {x};
    y = sub(y, true);

    if (y[0] == 2) {
        sub(y, true);
        cout << "= " << x << endl;
    }

    return y[0];
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
            for (int i = X + 3; i <= N * 2; ++i) {
                ys.push_back(i);
            }
            ys.insert(ys.begin() + N - 3, X + 2);
            ys.insert(ys.begin() + N - 2, X - 1);
            ys.insert(ys.begin() + N - 1, X);
            ys.insert(ys.begin() + N, X + 1);
            xs = ys;
        }

        for (int x : xs) {
            cout << x << endl;
        }
    }

    return 0;
}
