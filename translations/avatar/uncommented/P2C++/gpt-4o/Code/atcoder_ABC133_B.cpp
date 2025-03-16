#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double dist(const vector<int>& x, const vector<int>& y, int d) {
    double tmp = 0.0;
    for (int i = 0; i < d; i++) {
        tmp += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return sqrt(tmp);
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> points(n, vector<int>(d));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> points[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(points[i], points[j], d) == floor(dist(points[i], points[j], d))) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}

// <END-OF-CODE>
