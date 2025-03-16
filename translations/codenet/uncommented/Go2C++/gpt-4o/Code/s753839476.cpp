#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

double AbsDiff(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    int n;
    double t, a;
    cin >> n >> t >> a;

    vector<double> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    double minDiff = AbsDiff(t - heights[0] * 0.006, a);
    int minIdx = 0;
    for (int i = 1; i < n; ++i) {
        double diff = AbsDiff(t - heights[i] * 0.006, a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }
    cout << minIdx + 1 << endl;

    return 0;
}

// <END-OF-CODE>
