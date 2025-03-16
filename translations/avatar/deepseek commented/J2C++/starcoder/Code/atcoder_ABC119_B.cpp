#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> x(N);
    vector<string> u(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> u[i];
    }
    cout << solve(x, u) << endl;
    return 0;
}

double solve(vector<double> x, vector<string> u) {
    return accumulate(x.begin(), x.end(), 0.0, [u](double a, double b) { return a + b * (u[a] == "JPY"? 1 : 380000); });
}

