
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Create a Scanner object to read input from the user
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);

    // Read integer inputs A, B, H, and M from the user
    int A, B, H, M;
    std::cin >> A >> B >> H >> M;

    // Declare variables for calculations
    double ans2, kaku, mkaku, hkaku, AA2, BB2, CC, DD, dkaku, dans2;

    // Calculate the angle of the minute hand in degrees
    mkaku = M * 6;

    // Calculate the angle of the hour hand in degrees
    hkaku = H * 30 + (double) M / 2;

    // Calculate the difference in angles between the two hands
    kaku = mkaku - hkaku;

    // Convert the angle difference from degrees to radians
    dkaku = std::abs(std::cos(kaku));

    // Calculate the squares of A and B
    AA2 = A * A;
    BB2 = B * B;

    // Calculate the sum of squares of A and B
    CC = AA2 + BB2;

    // Calculate the cosine of the angle difference and adjust for the formula
    DD = dkaku * 2 * A * B;

    // Calculate the final result using the derived formula
    ans2 = CC - DD;

    // Convert the result to double for square root calculation
    dans2 = ans2;

    // Calculate the square root of the result
    double ans = std::sqrt(dans2);

    // Output the final result
    std::cout << ans << std::endl;

    return 0;
}
