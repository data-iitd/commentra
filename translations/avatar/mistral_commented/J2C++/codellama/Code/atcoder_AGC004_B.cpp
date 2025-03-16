#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    long x;

    cin >> N >> x;

    vector<long> srimeList(N);

    for (int i = 0; i < N; i++) {
        cin >> srimeList[i];
    }

    vector<vector<long>> costList(N, vector<long>(N));

    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    vector<long> result(N);

    for (int i = 0; i < N; i++) {
        long temp = i * x;
        for (long cost : costList[i]) {
            temp += cost;
        }
        result[i] = temp;
    }

    long minResult = result[0];
    for (int i = 1; i < N; i++) {
        if (result[i] < minResult) {
            minResult = result[i];
        }
    }

    cout << minResult << endl;

    return 0;
}

