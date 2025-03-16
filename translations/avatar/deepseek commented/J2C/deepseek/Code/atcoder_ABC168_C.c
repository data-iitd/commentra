#include <stdio.h>
#include <math.h>

int main() {
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);

    // Calculate the angles for the minute and hour hands in degrees
    double mkaku = M * 6.0; // Minute hand angle
    double hkaku = H * 30.0 + (double)M / 2.0; // Hour hand angle

    // Calculate the difference between the two angles
    double kaku = fabs(mkaku - hkaku);

    // Convert the angle difference to radians
    double dkaku = fabs(kaku * M_PI / 180.0);

    // Calculate the cosine of the angle in radians
    double cos_value = cos(dkaku);
    double ans2 = A * A + B * B - 2 * A * B * cos_value;

    // Calculate the square root of the distance
    double ans = sqrt(ans2);

    // Print the final answer
    printf("%.10f\n", ans);

    return 0;
}
