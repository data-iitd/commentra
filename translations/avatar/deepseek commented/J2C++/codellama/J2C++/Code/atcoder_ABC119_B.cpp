#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> x(N);
    vector<string> u(N);

    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        cin >> u[i];
    }

    cout << solve(x, u) << endl;
    return 0;
}

double solve(vector<double> x, vector<string> u) {
    double total = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (u[i] == "JPY") {
            total += x[i];
        } else {
            total += x[i] * 380000;
        }
    }
    return total;
}

