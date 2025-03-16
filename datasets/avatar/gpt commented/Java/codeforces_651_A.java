import java.io.*; 
import java.math.BigInteger; 
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input and a PrintWriter for output
        Scanner in = new Scanner(System.in); 
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read two integers from input
        int a = in.nextInt(), b = in.nextInt(); 
        int c = 0; // Initialize counter for the number of operations
        
        // Check for the special case where both a and b are 1
        if (a == 1 && b == 1) {
            pw.println(0); // Output 0 operations needed
        } else {
            // Loop until both a and b are non-positive
            while (a >= 1 || b >= 1) {
                // If a is greater than or equal to b, perform operation on a
                if (a >= b) {
                    b++; // Increment b
                    a -= 2; // Decrement a by 2
                } else {
                    // If b is greater than a, perform operation on b
                    a++; // Increment a
                    b -= 2; // Decrement b by 2
                }
                
                // Check if either a or b has become non-positive
                if (a <= 0 || b <= 0) {
                    c++; // Increment operation counter and break
                    break; 
                }
                c++; // Increment operation counter
            }
            // Output the total number of operations performed
            pw.println(c); 
        }
        
        // Close the PrintWriter
        pw.close(); 
    }

    // Swap method (not used in this code)
    static void swap(int a, int b) {
        int t = b; 
        b = a; 
        a = t; 
    }

    // Debug method for printing objects (not used in this code)
    static void debug(Object... obj) {
        System.err.println(Arrays.deepToString(obj)); 
    }
}
