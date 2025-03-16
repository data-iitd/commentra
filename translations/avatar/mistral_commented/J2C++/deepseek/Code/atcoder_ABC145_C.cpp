#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> pos(N, vector<int>(2));

    for (int i = 0; i < N; i++) {
        cin >> pos[i][0] >> pos[i][1];
    }

    double sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]);
        }
    }

    cout << fixed << setprecision(10) << sum / N << endl;

    return 0;
}

