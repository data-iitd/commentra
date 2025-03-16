
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int N;
    ss >> N;

    vector<int> X(N);
    vector<int> Y(N);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream ss(line);
        ss >> X[i];
        Y[i] = X[i];
    }

    sort(Y.begin(), Y.end());

    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];

    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            cout << m2 << endl;
        } else {
            cout << m1 << endl;
        }
    }

    return 0;
}

