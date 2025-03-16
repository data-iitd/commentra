
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the Euclidean distance between two points
double dist(vector<int> x, vector<int> y) {
    double tmp = 0.0;
    for (int i = 0; i < x.size(); i++) {
        tmp += pow(x[i] - y[i], 2);
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
            if (dist(points[i], points[j]) == (int)dist(points[i], points[j])) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

