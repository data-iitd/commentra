#include <stdio.h>
#include <math.h>

int main() {
    // Read input values for A, B, H, and M
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);
    
    // Calculate the angles for the minute and hour hands in degrees
    double mkaku = M * 6.0; // Minute hand angle
    double hkaku = H * 30.0; // Hour hand angle
    hkaku += (double)M / 2.0; // Adjust hour hand angle for minutes
    
    // Calculate the difference between the two angles
    double kaku = mkaku - hkaku;
    
    // Convert the angle difference to radians
    double dkaku = fabs(kaku * (M_PI / 180.0));
    
    // Calculate the cosine of the angle in radians
    double AA2 = (double)A * (double)A;
    double BB2 = (double)B * (double)B;
    double CC = AA2 + BB2;
    double DD = cos(dkaku) * 2.0 * (double)A * (double)B;
    
    // Calculate the distance using the cosine rule
    double ans2 = CC - DD;
    
    // Calculate the square root of the distance
    double ans = sqrt(ans2);
    
    // Print the final answer
    printf("%lf\n", ans);
    
    return 0;
}

// <END-OF-CODE>
