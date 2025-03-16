#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double AA = static_cast<double>(A);
    double BB = static_cast<double>(B);
    double HH = static_cast<double>(H);
    double MM = static_cast<double>(M);

    double mkaku = MM * 6.0;
    double hkaku = HH * 30.0 + (M / 2.0);
    double kaku = mkaku - hkaku;

    double dkaku = abs(kaku * M_PI / 180.0); // Convert degrees to radians

    double AA2 = AA * AA;
    double BB2 = BB * BB;
    double CC = AA2 + BB2;

    double DD = cos(dkaku) * 2.0 * AA * BB;
    double ans2 = CC - DD;

    double ans = sqrt(ans2);
    cout << fixed << setprecision(10) << ans << endl; // Set precision for output

    return 0;
}

// <END-OF-CODE>
