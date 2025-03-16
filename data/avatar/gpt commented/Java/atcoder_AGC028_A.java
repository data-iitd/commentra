import java.math.BigInteger; 
import java.util.*; 
import java.util.stream.*; 

public class Main { 
    // Create a scanner object for input
    static Scanner scanner = new Scanner(System.in); 
    
    public static void main(String[] $) { 
        // Read two integers n and m from input
        int n = scanner.nextInt(); 
        int m = scanner.nextInt(); 
        
        // Calculate the greatest common divisor (gcd) of n and m
        int gcd = BigInteger.valueOf(n).gcd(BigInteger.valueOf(m)).intValue(); 
        
        // Read two strings s and t from input
        String s = scanner.next(); 
        String t = scanner.next(); 
        
        // Check for mismatches in the characters of the two strings based on the gcd
        // If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
        System.out.println(
            IntStream.range(0, gcd)
                .filter(k -> s.charAt(k * n / gcd) != t.charAt(k * m / gcd)) // Filter indices where characters differ
                .mapToLong(k -> -1) // Map to -1 for mismatches
                .findAny() // Find any mismatch
                .orElse(BigInteger.valueOf(n).multiply(BigInteger.valueOf(m)).divide(BigInteger.valueOf(gcd)).longValue()) // Calculate lcm if no mismatch
        ); 
    } 
}
