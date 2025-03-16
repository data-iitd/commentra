#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

void solve(int N, vector<int>& x, vector<int>& y) {
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);

    double total_distance = 0.0;
    int count = 0;

    do {
        double current_distance = 0.0;
        for (int i = 0; i < N - 1; ++i) {
            int f = indices[i];
            int t = indices[i + 1];
            current_distance += sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
        }
        total_distance += current_distance;
        ++count;
    } while (next_permutation(indices.begin(), indices.end()));

    double result = total_distance / count;
    cout << result << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> x(N);
    vector<int> y(N);

    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    solve(N, x, y);

    return 0;
}

