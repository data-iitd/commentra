#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    long x;
    cin >> N >> x;
    vector<long> srimeList(N);
    for (int i = 0; i < N; i++) {
        cin >> srimeList[i];
    }
    vector<vector<long>> costList(N);
    for (int i = 0; i < N; i++) {
        costList[i].resize(N);
    }
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }
    vector<long> result;
    for (int i = 0; i < N; i++) {
        int j = i;
        result.push_back(i * x + accumulate(costList[i].begin(), costList[i].end(), 0L));
    }
    cout << *min_element(result.begin(), result.end()) << endl;
    return 0;
}
