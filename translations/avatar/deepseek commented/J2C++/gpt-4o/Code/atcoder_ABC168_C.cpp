#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Read input values for A, B, H, and M
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    // Calculate the angles for the minute and hour hands in degrees
    double mkaku = M * 6.0; // Minute hand angle
    double hkaku = H * 30.0; // Hour hand angle
    hkaku += M / 2.0; // Adjust hour hand angle for minutes

    // Calculate the difference between the two angles
    double kaku = mkaku - hkaku;

    // Convert the angle difference to radians
    double dkaku = fabs(kaku * M_PI / 180.0);

    // Calculate the cosine of the angle in radians
    double AA2 = A * A;
    double BB2 = B * B;
    double CC = AA2 + BB2;
    double DD = cos(dkaku) * 2 * A * B;

    // Calculate the distance using the cosine rule
    double ans2 = CC - DD;

    // Calculate the square root of the distance
    double ans = sqrt(ans2);

    // Print the final answer
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}

// <END-OF-CODE>
