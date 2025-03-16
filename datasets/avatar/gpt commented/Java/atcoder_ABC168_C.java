import java.util.*; 
import java.math.BigDecimal; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read integer inputs A, B, H, and M from the user
        int A = sc.nextInt(); 
        int B = sc.nextInt(); 
        int H = sc.nextInt(); 
        int M = sc.nextInt(); 
        
        // Convert integer inputs to BigDecimal for precise calculations
        BigDecimal AA = new BigDecimal(A); 
        BigDecimal BB = new BigDecimal(B); 
        BigDecimal HH = new BigDecimal(H); 
        BigDecimal MM = new BigDecimal(M); 
        
        // Declare variables for calculations
        BigDecimal ans2; 
        BigDecimal kaku; 
        BigDecimal mkaku; 
        BigDecimal hkaku; 
        BigDecimal AA2; 
        BigDecimal BB2; 
        BigDecimal CC; 
        BigDecimal DD; 
        double dkaku; 
        double dans2; 
        
        // Calculate the angle of the minute hand in degrees
        mkaku = MM.multiply(BigDecimal.valueOf(6)); 
        
        // Calculate the angle of the hour hand in degrees
        hkaku = HH.multiply(BigDecimal.valueOf(30)); 
        hkaku = hkaku.add(BigDecimal.valueOf((double) M / 2)); 
        
        // Calculate the difference in angles between the two hands
        kaku = mkaku.subtract(hkaku); 
        
        // Convert the angle difference from degrees to radians
        dkaku = Math.abs(Math.toRadians(kaku.doubleValue())); 
        
        // Calculate the squares of A and B
        AA2 = AA.multiply(AA); 
        BB2 = BB.multiply(BB); 
        
        // Calculate the sum of squares of A and B
        CC = AA2.add(BB2); 
        
        // Calculate the cosine of the angle difference and adjust for the formula
        DD = BigDecimal.valueOf(Math.cos(dkaku)); 
        DD = DD.multiply(BigDecimal.valueOf(2)); 
        DD = DD.multiply(AA); 
        DD = DD.multiply(BB); 
        
        // Calculate the final result using the derived formula
        ans2 = CC.subtract(DD); 
        
        // Convert the result to double for square root calculation
        dans2 = ans2.doubleValue(); 
        
        // Calculate the square root of the result
        double ans = Math.sqrt(dans2); 
        
        // Output the final result
        System.out.println(ans); 
    } 
}
