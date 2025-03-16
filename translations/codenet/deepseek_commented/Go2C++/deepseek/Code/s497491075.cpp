#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

// Function to read input from the standard input.
vector<int> readInput() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int N, D;
    ss >> N >> D;
    vector<int> points;
    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        stringstream ss2(line);
        int x, y;
        ss2 >> x >> y;
        points.push_back(x);
        points.push_back(y);
    }
    return points;
}

// Function to count points within the given distance.
int countPoints(const vector<int>& points, int D) {
    int count = 0;
    for (size_t i = 0; i < points.size(); i += 2) {
        int x = points[i];
        int y = points[i + 1];
        double distance = sqrt(x * x + y * y);
        if (distance <= D) {
            ++count;
        }
    }
    return count;
}

int main() {
    vector<int> points = readInput();
    int N = points[0];
    int D = points[1];
    int result = countPoints(points, D);
    cout << result << endl;
    return 0;
}
