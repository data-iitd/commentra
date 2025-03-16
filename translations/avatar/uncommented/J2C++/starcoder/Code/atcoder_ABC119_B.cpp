#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    double x[N], y[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(x, y) << endl;
}

double solve(double x[], string y[]) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if (y[i] == "JPY") {
            sum += x[i];
        } else {
            sum += x[i] * 380000;
        }
    }
    return sum;
}

