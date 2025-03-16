#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int A, B, H, M;
    double ans;
    double dkaku;
    double dans2;

    cin >> A >> B >> H >> M;

    BigDecimal AA(A);
    BigDecimal BB(B);
    BigDecimal HH(H);
    BigDecimal MM(M);

    BigDecimal mkaku = MM * 6;
    BigDecimal hkaku = HH * 30 + MM / 2;
    BigDecimal kaku = mkaku - hkaku;

    dkaku = abs(kaku.toRadians());

    BigDecimal AA2 = AA * AA;
    BigDecimal BB2 = BB * BB;
    BigDecimal CC = AA2 + BB2;
    BigDecimal DD = cos(dkaku) * AA * BB;

    BigDecimal ans2 = CC - DD;
    dans2 = ans2.toDouble();
    ans = sqrt(dans2);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}

