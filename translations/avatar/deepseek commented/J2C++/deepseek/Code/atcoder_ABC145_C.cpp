#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

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
            sum += sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2));
        }
    }

    cout << sum / N << endl;

    return 0;
}
