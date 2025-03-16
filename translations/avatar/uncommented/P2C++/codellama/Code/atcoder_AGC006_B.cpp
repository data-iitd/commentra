#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> xs;
    if (X == 1 || X == N * 2 - 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        if (X == N * 2 - 2) {
            for (int i = N - 1; i <= X + 2; i++) {
                xs.push_back(i);
            }
            for (int i = 1; i < N - 1; i++) {
                xs.push_back(i);
            }
        } else {
            vector<int> ys;
            for (int i = 1; i < X - 1; i++) {
                ys.push_back(i);
            }
            for (int i = X + 3; i <= N * 2; i++) {
                ys.push_back(i);
            }
            for (int i = 0; i < N - 3; i++) {
                xs.push_back(ys[i]);
            }
            xs.push_back(X + 2);
            xs.push_back(X - 1);
            xs.push_back(X);
            xs.push_back(X + 1);
            for (int i = N - 3; i < ys.size(); i++) {
                xs.push_back(ys[i]);
            }
        }
        for (int i = 0; i < xs.size(); i++) {
            cout << xs[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

