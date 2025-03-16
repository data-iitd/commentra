
#include <iostream>
#include <iomanip>
#include <cmath>
#include <bigdecimal.h>
using namespace std;

int main() {
    double N, d, x;
    cin >> N >> d >> x;
    BigDecimal ans("0.0");
    while (N > 0.5) {
        BigDecimal adnum(d + x * (N - 0.5));
        ans = ans + adnum;
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;
        N--;
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
