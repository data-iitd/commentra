#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Read integer inputs A, B, H, and M from the user
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    // Calculate the angle of the minute hand in degrees
    double mkaku = M * 6.0;

    // Calculate the angle of the hour hand in degrees
    double hkaku = H * 30.0 + (M / 2.0);

    // Calculate the difference in angles between the two hands
    double kaku = mkaku - hkaku;

    // Convert the angle difference from degrees to radians
    double dkaku = abs(kaku * M_PI / 180.0);

    // Calculate the squares of A and B
    double AA2 = A * A;
    double BB2 = B * B;

    // Calculate the sum of squares of A and B
    double CC = AA2 + BB2;

    // Calculate the cosine of the angle difference and adjust for the formula
    double DD = cos(dkaku) * 2 * A * B;

    // Calculate the final result using the derived formula
    double ans2 = CC - DD;

    // Calculate the square root of the result
    double ans = sqrt(ans2);

    // Output the final result
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}

// <END-OF-CODE>
