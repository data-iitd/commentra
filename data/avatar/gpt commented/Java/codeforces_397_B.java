import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.ArrayList; 
import java.util.Arrays; 
import java.util.Collection; 
import java.util.Collections; 
import java.util.Comparator; 
import java.util.HashMap; 
import java.util.HashSet; 
import java.util.InputMismatchException; 
import java.util.PriorityQueue; 
import java.util.Random; 
import java.util.Scanner; 
import java.util.Stack; 
import java.util.TreeMap; 
import java.util.TreeSet; 

public class Main { 
    // Define constants for the problem
    static int N; 
    static int MOD = (int) (1e9 + 7); 

    public static void main(String args[]) { 
        // Initialize scanner for input and print writer for output
        Scanner in = new Scanner(System.in); 
        PrintWriter out = new PrintWriter(System.out); 
        
        // Read the number of test cases
        int t = in.nextInt(); 
        
        // Process each test case
        while (t-- > 0) { 
            // Read input values for each test case
            long n = in.nextInt(); 
            long a = in.nextInt(); 
            long b = in.nextInt(); 
            
            // Check if n is less than a, if so, output "No"
            if (n < a) { 
                out.println("No"); 
                continue; 
            } 
            
            // If a equals b, check if n is a multiple of a
            if (a == b) { 
                if (n % a == 0) { 
                    out.println("Yes"); 
                } else { 
                    out.println("No"); 
                } 
                continue; 
            } 
            
            // Calculate the maximum number of a's that can fit into b
            long x = b / (b - a); 
            
            // If n is greater than x * a, output "Yes"
            if (n > x * a) { 
                out.println("Yes"); 
                continue; 
            } 
            
            // Binary search to find the largest mid such that mid * a < n
            long low = 1; 
            long high = x + 1; 
            long ans = 1; 
            while (low <= high) { 
                long mid = (low + high) / 2; 
                
                // Adjust the search range based on the condition
                if (mid * a < n) { 
                    low = mid + 1; 
                } else { 
                    ans = mid; 
                    high = mid - 1; 
                } 
            } 
            
            // Check the final conditions to determine output
            if (n > (ans - 1) * b && n < ans * a) { 
                out.println("No"); 
            } else { 
                out.println("Yes"); 
            } 
        } 
        
        // Close the output writer
        out.close(); 
    } 
}
