import java.util.*; // Importing the utility package for Scanner
import java.math.*; // Importing the math package for BigDecimal

public class Main {
    public static void main(String args[]) {
        // Creating a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Reading two strings from the user input
        String sa = sc.next();
        String sb = sc.next();
        
        // Converting the input strings to BigDecimal for precise arithmetic operations
        BigDecimal A = new BigDecimal(sa);
        BigDecimal B = new BigDecimal(sb);
        
        // Multiplying the two BigDecimal numbers and printing the result
        // The result is rounded down to the nearest whole number
        System.out.println(A.multiply(B).setScale(0, BigDecimal.ROUND_DOWN));
    }
}
