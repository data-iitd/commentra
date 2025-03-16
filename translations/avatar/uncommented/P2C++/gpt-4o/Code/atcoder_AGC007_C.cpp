#include <iostream>
#include <iomanip>

using namespace std;

double mainFunction(int N, double d, double x) {
    double ret = 0;
    while (N) {
        ret += d + (N - 0.5) * x;
        d = d + (d / N) + (5 * x) / (2 * N);
        x += 2 * x / N;
        N -= 1;
    }
    return ret;
}

int main() {
    int N;
    double d, x;
    cin >> N >> d >> x;
    cout << fixed << setprecision(10) << mainFunction(N, d, x) << endl;
    return 0;
}

// <END-OF-CODE>
