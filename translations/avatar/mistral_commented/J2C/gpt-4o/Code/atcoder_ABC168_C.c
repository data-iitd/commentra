#include <stdio.h>
#include <math.h>

int main() {
    int A, B, H, M; // Declare variables for input
    double mkaku, hkaku, kaku, dkaku, ans2, ans;

    // Reading the integer values A, B, H, M from the console
    scanf("%d %d %d %d", &A, &B, &H, &M);

    // Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
    mkaku = M * 6.0;
    hkaku = H * 30.0 + (M / 2.0);

    // Calculating kaku (difference between mkaku and hkaku)
    kaku = mkaku - hkaku;

    // Calculating the absolute value of kaku in radians
    dkaku = fabs(kaku * (M_PI / 180.0)); // Convert degrees to radians

    // Calculating the answer (square root of the difference between CC and DD)
    double AA2 = A * A; // A squared
    double BB2 = B * B; // B squared
    double CC = AA2 + BB2; // Sum of squares of A and B
    double DD = cos(dkaku) * A * B; // Cosine of kaku multiplied by A and B

    ans2 = CC - DD; // Difference
    ans = sqrt(ans2); // Square root of the difference

    // Printing the answer
    printf("%lf\n", ans);

    return 0;
}
