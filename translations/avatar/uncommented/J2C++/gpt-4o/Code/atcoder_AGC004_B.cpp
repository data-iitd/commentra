#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    long long N, x;
    cin >> N >> x;
    
    vector<long long> srimeList(N);
    for (long long i = 0; i < N; i++) {
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
        int j = i;
        long long sum = 0;
        for (int k = 0; k < N; k++) {
            sum += costList[k][j];
        }
        result[i] = i * x + sum;
    }
    
    cout << *min_element(result.begin(), result.end()) << endl;

    return 0;
}

// <END-OF-CODE>
