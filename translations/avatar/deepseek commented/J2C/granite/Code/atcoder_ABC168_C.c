

#include <stdio.h>
#include <math.h>

int main() {
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);

    double AA = A, BB = B, HH = H, MM = M;
    double mkaku = MM * 6; // Minute hand angle
    double hkaku = HH * 30; // Hour hand angle
    hkaku += (double) M / 2; // Adjust hour hand angle for minutes
    double kaku = mkaku - hkaku;

    double dkaku = fabs(kaku * M_PI / 180); // Convert angle difference to radians
    double AA2 = AA * AA;
    double BB2 = BB * BB;
    double CC = AA2 + BB2;
    double DD = 2 * cos(dkaku) * AA * BB;
    double ans2 = CC - DD; // Calculate distance using cosine rule
    double ans = sqrt(ans2); // Calculate square root of distance

    printf("%.10f\n", ans); // Print the final answer

    return 0;
}
// END-OF-CODE