
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

int main() { 
    // Declare variables for input and calculations
    int A, B, H, M; 
    double ans2; 
    double kaku; 
    double mkaku; 
    double hkaku; 
    double AA2; 
    double BB2; 
    double CC; 
    double DD; 
    double dkaku; 
    double dans2; 
    
    // Read integer inputs A, B, H, and M from the user
    scanf("%d %d %d %d", &A, &B, &H, &M); 
    
    // Calculate the angle of the minute hand in degrees
    mkaku = M * 6; 
    
    // Calculate the angle of the hour hand in degrees
    hkaku = H * 30 + (double) M / 2; 
    
    // Calculate the difference in angles between the two hands
    kaku = mkaku - hkaku; 
    
    // Convert the angle difference from degrees to radians
    dkaku = fabs(kaku * M_PI / 180); 
    
    // Calculate the squares of A and B
    AA2 = A * A; 
    BB2 = B * B; 
    
    // Calculate the sum of squares of A and B
    CC = AA2 + BB2; 
    
    // Calculate the cosine of the angle difference and adjust for the formula
    DD = cos(dkaku) * 2 * A * B; 
    
    // Calculate the final result using the derived formula
    ans2 = CC - DD; 
    
    // Calculate the square root of the result
    double ans = sqrt(ans2); 
    
    // Output the final result
    printf("%lf\n", ans); 
    
    return 0; 
}
