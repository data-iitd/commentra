#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int readInt() {
    int n = 0;
    char ch;
    while (true) {
        ch = cin.get();
        if (ch == ' ' || ch == '\n') {
            break;
        }
        n = n * 10 + (ch - '0');
    }
    return n;
}

double average(const vector<double>& s) {
    double sum = 0.0;
    for (double v : s) {
        sum += v;
    }
    return sum / s.size();
}

double diff(double a, double b) {
    return fabs(a - b);
}

int main() {
    int n = readInt();
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }

    double ave = average(a);

    double minDiff = numeric_limits<double>::max();
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double diffValue = diff(a[i], ave);
        if (diffValue < minDiff) {
            minDiff = diffValue;
            ansIndex = i;
        }
    }
    cout << ansIndex << endl;

    return 0;
}
