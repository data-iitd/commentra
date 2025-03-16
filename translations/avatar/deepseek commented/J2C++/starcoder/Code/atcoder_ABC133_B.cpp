
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<vector<int>> vectors(N, vector<int>(D));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> vectors[i][j];
        }
    }
    int answer = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist = 0;
            for (int d = 0; d < D; d++) {
                int x = (vectors[i][d] - vectors[j][d]);
                dist += (x * x);
            }
            double sq = sqrt(dist);
            // Check if the distance is an integer and increment the answer if it is
            answer += (abs(sq - floor(sq)) < 0.001? 1 : 0);
        }
    }
    cout << answer << endl;
    return 0;
}

