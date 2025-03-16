

#include <iostream>
#include <cmath>
#include <bigdecimal.h>

using namespace std;

int main() {
    // Read input values for A, B, H, and M
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    // Initialize BigDecimal variables for precision
    BigDecimal AA(A);
    BigDecimal BB(B);
    BigDecimal HH(H);
    BigDecimal MM(M);

    // Calculate the angles for the minute and hour hands in degrees
    BigDecimal mkaku = MM * 6; // Minute hand angle
    BigDecimal hkaku = HH * 30; // Hour hand angle
    hkaku = hkaku + (MM / 2); // Adjust hour hand angle for minutes

    // Calculate the difference between the two angles
    BigDecimal kaku = mkaku - hkaku;

    // Convert the angle difference to radians
    double dkaku = abs(kaku.toDouble());
    dkaku = dkaku * M_PI / 180;

    // Calculate the cosine of the angle in radians
    BigDecimal AA2 = AA * AA;
    BigDecimal BB2 = BB * BB;
    BigDecimal CC = AA2 + BB2;
    BigDecimal DD = BigDecimal(2 * cos(dkaku) * AA * BB);
    BigDecimal ans2 = CC - DD;

    // Convert the result to double for square root calculation
    double dans2 = ans2.toDouble();

    // Calculate the square root of the distance
    double ans = sqrt(dans2);

    // Print the final answer
    cout << ans << endl;

    return 0;
}

