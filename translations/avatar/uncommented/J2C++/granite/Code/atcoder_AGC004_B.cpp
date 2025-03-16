
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, x;
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
    vector<long> result;
    for (int i = 0; i < N; i++) {
        long sum = 0;
        for (int j = 0; j < N; j++) {
            sum += costList[j][i];
        }
        result.push_back(sum + (long)i * x);
    }
    cout << *min_element(result.begin(), result.end()) << endl;
    return 0;
}
