
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;
    double AA = A, BB = B, HH = H, MM = M;
    double ans2;
    double kaku, mkaku, hkaku, dkaku;
    mkaku = MM * 6;
    hkaku = HH * 30 + M / 2;
    kaku = mkaku - hkaku;
    dkaku = abs(atan(kaku / 180 * M_PI));
    AA *= AA;
    BB *= BB;
    double CC = AA + BB;
    double DD = 2 * cos(dkaku) * AA * BB;
    ans2 = CC - DD;
    double ans = sqrt(ans2);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
// END-OF-CODE