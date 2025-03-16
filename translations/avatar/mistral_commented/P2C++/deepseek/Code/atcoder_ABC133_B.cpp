#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate the Euclidean distance between two points
double dist(const vector<int>& x, const vector<int>& y) {
    double tmp = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        tmp += pow(x[i] - y[i], 2);
    }
    return sqrt(tmp);
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<vector<int>> points(n, vector<int>(d));
    for (auto& point : points) {
        for (int& coord : point) {
            cin >> coord;
        }
    }

    int count = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            if (floor(dist(points[i], points[j])) == dist(points[i], points[j])) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}
