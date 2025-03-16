#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long x;
    cin >> N >> x;
    vector<long long> srimeList(N);
    for (int i = 0; i < N; i++) {
        cin >> srimeList[i];
    }
    vector<vector<long long>> costList(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }
    vector<long long> result(N);
    for (int i = 0; i < N; i++) {
        long long temp = i * x;
        for (long long cost : costList[i]) {
            temp += cost;
        }
        result[i] = temp;
    }
    cout << *min_element(result.begin(), result.end()) << endl;
}

