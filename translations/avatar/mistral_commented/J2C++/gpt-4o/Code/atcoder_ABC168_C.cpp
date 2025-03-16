#include <iostream>   // For input and output
#include <cmath>     // For mathematical functions
#include <iomanip>   // For setting precision
#include <cstdlib>   // For std::abs

using namespace std;

int main() {
    int A, B, H, M; // Declaring variables for input

    // Reading the integer values A, B, H, and M from the console
    cin >> A >> B >> H >> M;

    // Declaring variables for intermediate calculations
    double mkaku, hkaku, kaku, ans2, CC, DD, ans;

    // Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
    mkaku = M * 6.0;
    hkaku = H * 30.0 + M / 2.0;

    // Calculating kaku (difference between mkaku and hkaku)
    kaku = mkaku - hkaku;

    // Calculating the absolute value of kaku in radians
    double dkaku = abs(kaku * (M_PI / 180.0)); // Convert degrees to radians

    // Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
    CC = (A * A) + (B * B);
    DD = cos(dkaku) * A * B;

    // Calculating the answer (square root of the difference between CC and DD)
    ans2 = CC - DD;
    ans = sqrt(ans2);

    // Printing the answer
    cout << fixed << setprecision(6) << ans << endl; // Set precision for output

    return 0;
}
