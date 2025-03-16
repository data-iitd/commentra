
#include <stdio.h>
#include <math.h>

int main() {
    // Read input values for A, B, H, and M
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);
    
    // Initialize BigDecimal variables for precision
    double AA = A;
    double BB = B;
    double HH = H;
    double MM = M;
    
    // Calculate the angles for the minute and hour hands in degrees
    double mkaku = MM * 6; // Minute hand angle
    double hkaku = HH * 30 + (double) M / 2; // Hour hand angle
    
    // Calculate the difference between the two angles
    double kaku = mkaku - hkaku;
    
    // Convert the angle difference to radians
    double dkaku = fabs(kaku * M_PI / 180);
    
    // Calculate the cosine of the angle in radians
    double AA2 = AA * AA;
    double BB2 = BB * BB;
    double CC = AA2 + BB2;
    double DD = 2 * AA * BB * cos(dkaku);
    
    // Calculate the distance using the cosine rule
    double ans2 = CC - DD;
    
    // Calculate the square root of the distance
    double ans = sqrt(ans2);
    
    // Print the final answer
    printf("%.10lf\n", ans);
    
    // End of code
    return 0;
}

