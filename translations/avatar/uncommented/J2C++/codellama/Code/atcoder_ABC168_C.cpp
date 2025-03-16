
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int A, B, H, M;
    double ans, dkaku, dans2;
    cin >> A >> B >> H >> M;
    double AA = A, BB = B, HH = H, MM = M;
    double mkaku = MM * 6, hkaku = HH * 30 + M / 2;
    hkaku = hkaku - mkaku;
    double kaku = hkaku;
    dkaku = abs(kaku * 3.14159265358979323846 / 180);
    double AA2 = AA * AA, BB2 = BB * BB, CC = AA2 + BB2;
    double DD = cos(dkaku) * 2 * AA * BB;
    double ans2 = CC - DD;
    dans2 = ans2;
    ans = sqrt(ans2);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
