#include <iostream>
#include <vector>
#include <string>
#include <numeric> // For std::accumulate

using namespace std;

double solve(const vector<double>& x, const vector<string>& u) {
    double total = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        if (u[i] == "JPY") {
            total += x[i];
        } else if (u[i] == "BTC") {
            total += x[i] * 380000.0;
        }
    }
    return total;
}

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
