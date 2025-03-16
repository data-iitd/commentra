
#include <iostream> 
#include <cmath> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    int A, B, H, M; 
    cin >> A >> B >> H >> M; 
    
    // Convert integer inputs to double for precise calculations
    double AA = A; 
    double BB = B; 
    double HH = H; 
    double MM = M; 
    
    // Declare variables for calculations
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
    
    // Calculate the angle of the minute hand in degrees
    mkaku = MM * 6; 
    
    // Calculate the angle of the hour hand in degrees
    hkaku = HH * 30 + (double) M / 2; 
    
    // Calculate the difference in angles between the two hands
    kaku = mkaku - hkaku; 
    
    // Convert the angle difference from degrees to radians
    dkaku = abs(kaku * M_PI / 180); 
    
    // Calculate the squares of A and B
    AA2 = AA * AA; 
    BB2 = BB * BB; 
    
    // Calculate the sum of squares of A and B
    CC = AA2 + BB2; 
    
    // Calculate the cosine of the angle difference and adjust for the formula
    DD = 2 * AA * BB * cos(dkaku); 
    
    // Calculate the final result using the derived formula
    ans2 = CC - DD; 
    
    // Convert the result to double for square root calculation
    dans2 = ans2; 
    
    // Calculate the square root of the result
    double ans = sqrt(dans2); 
    
    // Output the final result
    cout << ans << endl; 
    
    return 0; 
} 

