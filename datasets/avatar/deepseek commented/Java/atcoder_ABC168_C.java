
import java.util.* ;
import java.math.BigDecimal ;

public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;
        
        // Read input values for A, B, H, and M
        int A = sc.nextInt() ;
        int B = sc.nextInt() ;
        int H = sc.nextInt() ;
        int M = sc.nextInt() ;
        
        // Initialize BigDecimal variables for precision
        BigDecimal AA = new BigDecimal(A) ;
        BigDecimal BB = new BigDecimal(B) ;
        BigDecimal HH = new BigDecimal(H) ;
        BigDecimal MM = new BigDecimal(M) ;
        
        // Calculate the angles for the minute and hour hands in degrees
        BigDecimal mkaku = MM.multiply(BigDecimal.valueOf(6)) ; // Minute hand angle
        BigDecimal hkaku = HH.multiply(BigDecimal.valueOf(30)) ; // Hour hand angle
        hkaku = hkaku.add(BigDecimal.valueOf((double) M / 2)) ; // Adjust hour hand angle for minutes
        
        // Calculate the difference between the two angles
        BigDecimal kaku = mkaku.subtract(hkaku) ;
        
        // Convert the angle difference to radians
        double dkaku = Math.abs(Math.toRadians(kaku.doubleValue())) ;
        
        // Calculate the cosine of the angle in radians
        BigDecimal AA2 = AA.multiply(AA) ;
        BigDecimal BB2 = BB.multiply(BB) ;
        BigDecimal CC = AA2.add(BB2) ;
        BigDecimal DD = BigDecimal.valueOf(Math.cos(dkaku)) ;
        DD = DD.multiply(BigDecimal.valueOf(2)) ;
        DD = DD.multiply(AA) ;
        DD = DD.multiply(BB) ;
        
        // Calculate the distance using the cosine rule
        BigDecimal ans2 = CC.subtract(DD) ;
        
        // Convert the result to double for square root calculation
        double dans2 = ans2.doubleValue() ;
        
        // Calculate the square root of the distance
        double ans = Math.sqrt(dans2) ;
        
        // Print the final answer
        System.out.println(ans) ;
    }
}
