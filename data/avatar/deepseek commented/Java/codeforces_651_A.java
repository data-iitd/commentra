import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initialize Scanner for input
        PrintWriter pw = new PrintWriter(System.out); // Initialize PrintWriter for output
        int a = in.nextInt(); // Read first integer input
        int b = in.nextInt(); // Read second integer input
        int c = 0; // Initialize counter

        if (a == 1 && b == 1) { // Check if both a and b are 1
            pw.println(0); // Print 0 if true
        } else {
            while (a >= 1 || b >= 1) { // Continue until a or b is less than or equal to 0
                if (a >= b) { // If a is greater than or equal to b
                    b++; // Increment b
                    a -= 2; // Decrement a by 2
                } else { // If b is greater than a
                    a++; // Increment a
                    b -= 2; // Decrement b by 2
                }
                if (a <= 0 || b <= 0) { // Check if either a or b is less than or equal to 0
                    c++; // Increment counter and break the loop
                    break;
                }
                c++; // Increment counter in each iteration
            }
            pw.println(c); // Print the final value of counter
        }
        pw.close(); // Close the PrintWriter
    }

    static void swap(int a, int b) { // Utility method to swap two integers
        int t = b;
        b = a;
        a = t;
    }

    static void debug(Object... obj) { // Utility method for debugging
        System.err.println(Arrays.deepToString(obj));
    }
}
