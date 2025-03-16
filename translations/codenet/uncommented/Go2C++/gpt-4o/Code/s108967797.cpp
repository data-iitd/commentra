#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

double ave(const vector<double>& s) {
    double sum = 0;
    for (double v : s) {
        sum += v;
    }
    return sum / s.size();
}

double diff(double a, double b) {
    return fabs(a - b);
}

int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double average = ave(a);

    double minDiff = numeric_limits<double>::max();
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double difference = diff(a[i], average);
        if (difference < minDiff) {
            minDiff = difference;
            ansIndex = i;
        }
    }
    cout << ansIndex << endl;

    return 0;
}

// <END-OF-CODE>
