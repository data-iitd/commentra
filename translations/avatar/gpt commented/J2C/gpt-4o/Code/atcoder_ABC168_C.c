#include <stdio.h>
#include <math.h>

int main() {
    // Declare variables for inputs
    int A, B, H, M;
    
    // Read integer inputs A, B, H, and M from the user
    scanf("%d %d %d %d", &A, &B, &H, &M);
    
    // Declare variables for calculations
    double mkaku, hkaku, kaku, dkaku;
    double AA, BB, CC, DD, ans2, ans;

    // Calculate the angle of the minute hand in degrees
    mkaku = M * 6.0;

    // Calculate the angle of the hour hand in degrees
    hkaku = H * 30.0 + (M / 2.0);

    // Calculate the difference in angles between the two hands
    kaku = mkaku - hkaku;

    // Convert the angle difference from degrees to radians
    dkaku = fabs(kaku * (M_PI / 180.0));

    // Calculate the squares of A and B
    AA = A * A;
    BB = B * B;

    // Calculate the sum of squares of A and B
    CC = AA + BB;

    // Calculate the cosine of the angle difference and adjust for the formula
    DD = 2 * cos(dkaku) * A * B;

    // Calculate the final result using the derived formula
    ans2 = CC - DD;

    // Calculate the square root of the result
    ans = sqrt(ans2);

    // Output the final result
    printf("%lf\n", ans);

    return 0;
}

// <END-OF-CODE>
