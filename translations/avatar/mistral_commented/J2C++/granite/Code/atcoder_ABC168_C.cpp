
#include <iostream>
#include <cmath>
#include <bigdecimal.h>

using namespace std;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    BigDecimal AA(A);
    BigDecimal BB(B);
    BigDecimal HH(H);
    BigDecimal MM(M);

    BigDecimal ans2;
    BigDecimal kaku;
    BigDecimal mkaku;
    BigDecimal hkaku;
    BigDecimal AA2;
    BigDecimal BB2;
    BigDecimal CC;
    BigDecimal DD;
    double dkaku;
    double dans2;

    mkaku = MM * 6;
    hkaku = HH * 30 + MM / 2;
    kaku = mkaku - hkaku;

    dkaku = abs(kaku.toDouble());

    AA2 = AA * AA;
    BB2 = BB * BB;

    CC = AA2 + BB2;
    DD = BigDecimal(cos(dkaku)) * AA * BB;

    ans2 = CC - DD;
    dans2 = ans2.toDouble();
    ans = sqrt(dans2);

    cout << ans << endl;

    return 0;
}
