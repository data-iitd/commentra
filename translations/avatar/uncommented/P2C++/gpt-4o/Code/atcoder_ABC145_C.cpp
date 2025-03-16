#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

void solve(int N, vector<int>& x, vector<int>& y) {
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, ..., N-1
    vector<double> distances;

    do {
        double total_distance = 0.0;
        for (int i = 0; i < N - 1; ++i) {
            int f = indices[i];
            int t = indices[i + 1];
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            total_distance += distance;
        }
        distances.push_back(total_distance);
    } while (next_permutation(indices.begin(), indices.end()));

    double result = accumulate(distances.begin(), distances.end(), 0.0) / distances.size();
    cout << result << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    solve(N, x, y);
    return 0;
}

// <END-OF-CODE>
