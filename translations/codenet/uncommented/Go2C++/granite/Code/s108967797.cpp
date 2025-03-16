
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double ave = 0;
    for (int i = 0; i < n; i++) {
        ave += a[i];
    }
    ave /= n;

    double minDiff = 1e9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double diff = abs(a[i] - ave);
        if (diff < minDiff) {
            minDiff = diff;
            ansIndex = i;
        }
    }
    cout << ansIndex << endl;
}

