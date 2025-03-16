#include <stdio.h> 
#include <math.h> 

int main() { 
    // Create a Scanner object to read input from the user
    int A, B, H, M; 
    double AA, BB, HH, MM, ans2, kaku, mkaku, hkaku, AA2, BB2, CC, DD, dkaku, dans2; 
    printf("Enter A, B, H, and M: "); 
    scanf("%d %d %d %d", &A, &B, &H, &M); 
    
    // Convert integer inputs to double for precise calculations
    AA = A; 
    BB = B; 
    HH = H; 
    MM = M; 
    
    // Calculate the angle of the minute hand in degrees
    mkaku = MM * 6; 
    
    // Calculate the angle of the hour hand in degrees
    hkaku = HH * 30 + (double) M / 2; 
    
    // Calculate the difference in angles between the two hands
    kaku = mkaku - hkaku; 
    
    // Convert the angle difference from degrees to radians
    dkaku = fabs(radians(kaku)); 
    
    // Calculate the squares of A and B
    AA2 = AA * AA; 
    BB2 = BB * BB; 
    
    // Calculate the sum of squares of A and B
    CC = AA2 + BB2; 
    
    // Calculate the cosine of the angle difference and adjust for the formula
    DD = cos(dkaku) * 2 * AA * BB; 
    
    // Calculate the final result using the derived formula
    ans2 = CC - DD; 
    
    // Convert the result to double for square root calculation
    dans2 = ans2; 
    
    // Calculate the square root of the result
    double ans = sqrt(dans2); 
    
    // Output the final result
    printf("The distance between the two hands is %f\n", ans); 
    return 0; 
} 
