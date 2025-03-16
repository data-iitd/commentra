#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

int main() {
    int A, B, H, M;
    std::cin >> A >> B >> H >> M;

    // Calculate the angles for the minute and hour hands in degrees
    double mkaku = M * 6; // Minute hand angle
    double hkaku = H * 30 + M / 2.0; // Hour hand angle

    // Calculate the difference between the two angles
    double kaku = std::abs(mkaku - hkaku);

    // Convert the angle difference to radians
    double dkaku = kaku * M_PI / 180.0;

    // Calculate the cosine of the angle in radians
    double cos_value = cos(dkaku);
    double ans2 = A * A + B * B - 2 * A * B * cos_value;

    // Calculate the square root of the distance
    double ans = sqrt(ans2);

    // Print the final answer with precision
    std::cout << std::fixed << std::setprecision(20) << ans << std::endl;

    return 0;
}
