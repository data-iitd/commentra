
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void Run(istream& r, ostream& w) {
    string line;
    getline(r, line);
    stringstream ss(line);
    int N, D;
    ss >> N >> D;

    vector<pair<int, int>> points;
    for (int i = 0; i < N; i++) {
        getline(r, line);
        stringstream ss(line);
        int x, y;
        ss >> x >> y;
        points.push_back(make_pair(x, y));
    }

    int count = 0;
    for (auto point : points) {
        double distance = sqrt(point.first * point.first + point.second * point.second);
        if (distance <= D) {
            count++;
        }
    }

    w << count << endl;
}

int main() {
    Run(cin, cout);
}

// END-OF-CODE