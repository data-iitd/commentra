
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    int points[n][d];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> points[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double tmp = 0.0;
            for (int k = 0; k < d; k++) {
                tmp += (points[i][k] - points[j][k]) * (points[i][k] - points[j][k]);
            }
            if (sqrt(tmp) == (int)sqrt(tmp)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

